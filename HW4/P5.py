import numpy as np
from scipy.optimize import fsolve
from scipy.integrate import solve_ivp, solve_bvp
import matplotlib.pyplot as plt

# Params
g_val = 0.0       # part (c): g=0
a     = 2.0       # thrust acceleration m/s^2
h     = 5000.0    # target altitude m
tf    = 200.0     # final time s

# ANALYTIC SOLUTION
# tan(beta) = tan_b0 - c*t  →  beta(t) = atan(tan_b0 - c*t)
# Shoot on (tan_b0, c) to hit v(tf)=0, y(tf)=h

def simulate_analytic(params, g=0.0):
    """Integrate state equations given (tan_b0, c). Returns full trajectory."""
    tan_b0, c = params
    def odes(t, z):
        u, v, x, y = z
        beta = np.arctan(tan_b0 - c*t)
        return [a*np.cos(beta), a*np.sin(beta) - g, u, v]

    sol = solve_ivp(odes, [0, tf], [0,0,0,0],
                    t_eval=np.linspace(0, tf, 2000), rtol=1e-10, atol=1e-12)
    return sol

def shooting_residuals(params, g=0.0):
    """Residuals: v(tf)=0, y(tf)=h."""
    sol = simulate_analytic(params, g)
    v_tf = sol.y[1, -1]
    y_tf = sol.y[3, -1]
    return [v_tf, y_tf - h]

# Solve analytic
params0 = [0.5, 0.005]     # initial guess for (tan_b0, c)
params_analytic = fsolve(shooting_residuals, params0, args=(g_val,),
                         full_output=False, xtol=1e-12)
tan_b0, c = params_analytic
print(f"Analytic solution:")
print(f"  tan(β₀) = {tan_b0:.6f}  →  β₀ = {np.degrees(np.arctan(tan_b0)):.3f}°")
print(f"  c       = {c:.6f}")

sol_a = simulate_analytic(params_analytic, g_val)
print(f"  v(tf)   = {sol_a.y[1,-1]:.4e}  (should be 0)")
print(f"  y(tf)   = {sol_a.y[3,-1]:.4f}  (should be {h})")
print(f"  u(tf)   = {sol_a.y[0,-1]:.4f}  m/s  (maximized terminal velocity)")


# NUMERICAL BVP SOLUTION
# State: z = [u, v, x, y, p_u, p_v, p_x, p_y]  (8 states, fixed tf)
# Control from Hu=0: tan(beta) = p_v/p_u  →  beta = atan2(p_v, p_u)

def bvp_odes(t, z):
    u, v, x, y, p_u, p_v, p_x, p_y = z
    beta = np.arctan2(-p_v, -p_u)           
    du  =  a * np.cos(beta)
    dv  =  a * np.sin(beta) - g_val
    dx  =  u
    dy  =  v
    dp_u = -p_x
    dp_v = -p_y
    dp_x =  0.0 * t
    dp_y =  0.0 * t
    return np.vstack([du, dv, dx, dy, dp_u, dp_v, dp_x, dp_y])

def bvp_bcs(za, zb):
    u0, v0, x0, y0, pu0, pv0, px0, py0 = za
    utf, vtf, xtf, ytf, putf, pvtf, pxtf, pytf = zb
    return np.array([
        u0,           # u(0) = 0
        v0,           # v(0) = 0
        x0,           # x(0) = 0
        y0,           # y(0) = 0
        vtf,          # v(tf) = 0         [terminal constraint]
        ytf - h,      # y(tf) = h         [terminal constraint]
        putf + 1.0,   # p_u(tf) = -1      [u free, dh/du = -1]
        pxtf,         # p_x(tf) = 0       [x free, dh/dx = 0]
        # p_v(tf) = nu1  LEFT FREE → determined by v(tf)=0
        # p_y(tf) = nu2  LEFT FREE → determined by y(tf)=h
    ])

# Initial guess: linear interpolation using analytic solution as warm start
t_mesh = np.linspace(0, tf, 200)
u_g = sol_a.y[0]; v_g = sol_a.y[1]
x_g = sol_a.y[2]; y_g = sol_a.y[3]

# Costate guess from analytic: p_u=-1, p_x=0, p_v linear, p_y=c
p_u_g  = -1.0 * np.ones_like(t_mesh)
p_x_g  =  0.0 * np.ones_like(t_mesh)
p_y_g  = -c   * np.ones_like(t_mesh)
p_v_g  = np.array([tan_b0 - c*ti for ti in t_mesh]) * (-1)   # p_v = -tan(beta)*p_u = tan(beta)

# Interpolate state guess onto mesh
from scipy.interpolate import interp1d
t_fine = np.linspace(0, tf, 2000)
interp = lambda arr: interp1d(t_fine, arr)(t_mesh)

y_guess = np.vstack([
    interp(sol_a.y[0]),   # u
    interp(sol_a.y[1]),   # v
    interp(sol_a.y[2]),   # x
    interp(sol_a.y[3]),   # y
    p_u_g,
    p_v_g,
    p_x_g,
    p_y_g,
])

sol_bvp = solve_bvp(bvp_odes, bvp_bcs, t_mesh, y_guess,
                    tol=1e-8, max_nodes=5000, verbose=1)

print(f"\nBVP solution:")
print(f"  Status: {sol_bvp.message}")
print(f"  v(tf)  = {sol_bvp.y[1,-1]:.4e}  (should be 0)")
print(f"  y(tf)  = {sol_bvp.y[3,-1]:.4f}  (should be {h})")
print(f"  u(tf)  = {sol_bvp.y[0,-1]:.4f}  m/s")


# COMPARISON PLOTS

t_an  = np.linspace(0, tf, 2000)
beta_an  = np.arctan(tan_b0 - c * t_an)
beta_num = np.arctan2(sol_bvp.y[5], sol_bvp.y[4])   # atan2(p_v, p_u)

fig, axes = plt.subplots(3, 2, figsize=(13, 7))
fig.suptitle("Thrust Vector Control — Linear Tangent Law\n"
             f"g={g_val}, a={a} m/s², h={h} m, tf={tf} s",
             fontsize=13, fontweight='bold')

labels = [('u(t)  [m/s]', 0), ('v(t)  [m/s]', 1),
          ('x(t)  [m]',   2), ('y(t)  [m]',   3)]

for idx, (ylabel, si) in enumerate(labels):
    r, c_idx = divmod(idx, 2)
    ax = axes[r, c_idx]
    ax.plot(t_an, sol_a.y[si],          color='#2563eb', lw=2,   label='Analytic')
    ax.plot(sol_bvp.x, sol_bvp.y[si],  color='#dc2626', lw=1.5,
            ls='--', label='Numerical BVP')
    ax.set_ylabel(ylabel); ax.grid(alpha=0.3); ax.legend(fontsize=8)

# beta(t) comparison
ax5 = axes[2, 0]
ax5.plot(t_an,       np.degrees(beta_an),            color='#2563eb', lw=2,   label='Analytic')
ax5.plot(sol_bvp.x,  np.degrees(beta_num),           color='#dc2626', lw=1.5,
         ls='--', label='Numerical BVP')
ax5.set_ylabel('β(t)  [deg]'); ax5.set_xlabel('Time (s)')
ax5.grid(alpha=0.3); ax5.legend(fontsize=8)

ax6 = axes[2, 1]
ax6.plot(t_an,      tan_b0 - c*t_an,                       color='#2563eb', lw=2,   label='Analytic (linear)')
ax6.plot(sol_bvp.x, sol_bvp.y[5]/sol_bvp.y[4],            color='#dc2626', lw=1.5,
         ls='--', label='Numerical p_v/p_u')
ax6.set_ylabel('tan β(t)'); ax6.set_xlabel('Time (s)')
ax6.set_title('Linear tangent law verification')
ax6.grid(alpha=0.3); ax6.legend(fontsize=8)

plt.tight_layout()
plt.savefig('HW4/thrust_vector.png', dpi=150, bbox_inches='tight')
plt.show()

print(f"\n── Terminal velocity comparison ──")
print(f"  Analytic u(tf)  = {sol_a.y[0,-1]:.6f} m/s")
print(f"  Numerical u(tf) = {sol_bvp.y[0,-1]:.6f} m/s")
print(f"  Difference      = {abs(sol_a.y[0,-1] - sol_bvp.y[0,-1]):.2e} m/s")