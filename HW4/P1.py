import numpy as np
from scipy.optimize import fsolve
import matplotlib.pyplot as plt

def residuals(z, alpha, b):
    c1, c2, v1, v2, tf = z

    eq1 = c2 - (c1 * tf) / 2                                         
    eq2 = ( ( (c1*tf**3)/(6*b)) - ((c2*tf**2)/(2*b)) + 10 )**2 + (tf-5)**2 - 4
    eq3 = c1 - 2 * v2 * ( ( (c1*tf**3)/(6*b)) - ((c2*tf**2)/(2*b)) + 10 )
    eq4 = -c1 * tf + c2 - v1
    eq5 = (-1/(2*b)) * (c1*tf - c2)**2 + alpha*tf + 2*v2*(tf-5)
    return [eq1, eq2, eq3, eq4, eq5]

def simulate(solution, b):
    """Given fsolve solution, compute state and control trajectories."""
    c1, c2, v1, v2, tf = solution
    t  = np.linspace(0, tf, 2000)
    u  = (c1*t - c2) / b
    x1 = 10 + c1*t**3/(6*b) - c2*t**2/(2*b)    # y(t)
    x2 = c1*t**2/(2*b) - c2*t/b                 # ydot(t)
    return t, x1, x2, u

def verify(solution, b, label):
    """Print terminal condition checks."""
    c1, c2, v1, v2, tf = solution
    t, x1, x2, u = simulate(solution, b)
    print(f"\n--- {label} ---")
    print(f"  c1={c1:.5f}, c2={c2:.5f}, nu1={v1:.5f}, nu2={v2:.5f}, tf={tf:.5f}")
    print(f"  y(tf)            = {x1[-1]:.6f}   (on manifold)")
    print(f"  ydot(tf)         = {x2[-1]:.2e}  (should be ~0)")
    print(f"  manifold residual= {x1[-1]**2 + (tf-5)**2 - 4:.2e}  (should be ~0)")
    print(f"  residual norm    = {np.linalg.norm(residuals(solution, alpha, b)):.2e}")


# SOLVE

# Case 1: alpha = 0.1, b = 1
alpha, b = 0.1, 1
initial_guess = [1, 1, 1, 1, 5]
solution1 = fsolve(residuals, initial_guess, args=(alpha, b))
verify(solution1, b, "Case 1: alpha=0.1, b=1")

# Case 2: alpha = 100, b = 1
alpha, b = 100, 1
initial_guess = [1, 1, 1, 1, 5]
solution2 = fsolve(residuals, initial_guess, args=(alpha, b))
verify(solution2, b, "Case 2: alpha=100, b=1")


# PLOT TRAJECTORIES

fig, axes = plt.subplots(3, 2, figsize=(12, 9))
fig.suptitle(r"Optimal Control: $\dot{y}(t_f)=0$, $y^2(t_f)+(t_f-5)^2=4$",
             fontsize=13, fontweight='bold')

cases = [
    (solution1, 1, "α=0.1, b=1", "#2563eb"),
    (solution2, 1, "α=100, b=1",  "#d12121"),
]

for j, (sol, b, label, color) in enumerate(cases):
    t, x1, x2, u = simulate(sol, b)
    tf = sol[4]

    # y(t)
    axes[0,j].plot(t, x1, color=color, lw=2)
    axes[0,j].axvline(tf, color='k', ls='--', lw=1, label=f'$t_f$={tf:.3f}')
    axes[0,j].plot(tf, x1[-1], 'o', color=color, ms=7)
    axes[0,j].set_title(label); axes[0,j].set_ylabel('$y(t)$')
    axes[0,j].legend(fontsize=9); axes[0,j].grid(alpha=0.3)

    # ydot(t)
    axes[1,j].plot(t, x2, color=color, lw=2)
    axes[1,j].axvline(tf, color='k', ls='--', lw=1)
    axes[1,j].axhline(0, color='gray', ls=':', lw=1)
    axes[1,j].plot(tf, x2[-1], 'o', color=color, ms=7)
    axes[1,j].set_ylabel(r'$\dot{y}(t)$'); axes[1,j].grid(alpha=0.3)

    # u(t)
    axes[2,j].plot(t, u, color=color, lw=2,
                   label=r'$u(t)=\frac{c_1}{b}(t - t_f/2)$')
    axes[2,j].axvline(tf, color='k', ls='--', lw=1)
    axes[2,j].axhline(0, color='gray', ls=':', lw=1)
    axes[2,j].set_ylabel('$u(t)$'); axes[2,j].set_xlabel('Time (s)')
    axes[2,j].legend(fontsize=9); axes[2,j].grid(alpha=0.3)

plt.tight_layout()


# TERMINAL MANIFOLD PLOT

fig2, ax = plt.subplots(figsize=(5, 5))
theta = np.linspace(0, 2*np.pi, 400)
ax.plot(5 + 2*np.cos(theta), 2*np.sin(theta), 'k--', lw=1.5,
        label='$y^2(t_f)+(t_f-5)^2=4$')

for sol, b, label, color in cases:
    t, x1, _, _ = simulate(sol, b)
    tf = sol[4]
    ax.plot(tf, x1[-1], '*', color=color, ms=14, label=f"{label}: $t_f$={tf:.3f}")

ax.set_xlabel('$t_f$'); ax.set_ylabel('$y(t_f)$')
ax.set_title('Solutions on Terminal Manifold')
ax.legend(fontsize=9); ax.grid(alpha=0.3); ax.set_aspect('equal')

plt.show()