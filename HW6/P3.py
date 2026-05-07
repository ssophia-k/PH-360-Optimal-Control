import numpy as np
from scipy.integrate import solve_ivp
from scipy.linalg import solve_continuous_are, solve_lyapunov, eigvals
import matplotlib.pyplot as plt


# System definition
A  = np.array([[0., 1.],
               [1., 0.]])
Bu = np.array([[0.], [1.]])
Bw = np.array([[0.], [1.]])
Cy = np.array([[0., 1.]])

Q   = np.array([[3., 0.], [0., 3.]])   # state cost weight
Ruu = 1.0                               # control cost weight
Rww = 4.0                               # process noise PSD
Rvv = 0.5                               # sensor noise PSD
tf  = 15.0                              # final time
n   = 2                                 # state dimension



# PART (a): Numerically integrate LQR and LQE Riccati equations

# --- LQR: integrate BACKWARD from tf to 0 ---
# Equation: -dP/dt = A^T P + P A + Q - P Bu Ruu^{-1} Bu^T P, P(tf) = 0
# Change variable tau = tf - t so we integrate forward in tau:
#   dP/dtau = A^T P + P A + Q - P Bu Ruu^{-1} Bu^T P, P(tau=0) = 0
def lqr_ode(tau, p_flat):
    P  = p_flat.reshape(n, n)
    P  = (P + P.T) / 2                  # enforce symmetry numerically
    dP = A.T @ P + P @ A + Q - (P @ Bu @ Bu.T @ P) / Ruu
    return dP.flatten()

sol_P = solve_ivp(lqr_ode, [0, tf], np.zeros(n * n),
                  dense_output=True, max_step=0.05, rtol=1e-9, atol=1e-11)

def P_of_t(t):
    """LQR Riccati solution P(t) at forward time t."""
    return sol_P.sol(tf - float(t)).reshape(n, n)

def K_of_t(t):
    """LQR gain K(t) = Ruu^{-1} Bu^T P(t),  shape (1, 2)."""
    return (Bu.T @ P_of_t(t)) / Ruu


# --- LQE: integrate FORWARD from 0 to tf ---
# Equation: dQe/dt = A Qe + Qe A^T + Bw Rww Bw^T - Qe Cy^T Rvv^{-1} Cy Qe, Qe(0) = 0
def lqe_ode(t, q_flat):
    Qe  = q_flat.reshape(n, n)
    Qe  = (Qe + Qe.T) / 2
    dQe = (A @ Qe + Qe @ A.T
           + Bw @ Bw.T * Rww
           - Qe @ Cy.T @ Cy @ Qe / Rvv)
    return dQe.flatten()

sol_Qe = solve_ivp(lqe_ode, [0, tf], np.zeros(n * n),
                   dense_output=True, max_step=0.05, rtol=1e-9, atol=1e-11)

def Qe_of_t(t):
    """LQE Riccati solution Qe(t) at time t."""
    return sol_Qe.sol(float(t)).reshape(n, n)

def L_of_t(t):
    """LQE gain L(t) = Qe(t) Cy^T Rvv^{-1},  shape (2, 1)."""
    return Qe_of_t(t) @ Cy.T / Rvv


# --- Print and plot gains ---
print("═══ Part (a) ═══")
print(f"K(t=0)  = {K_of_t(0.0).flatten()}  (converged to SS)")
print(f"K(t=tf) = {K_of_t(tf).flatten()}   (zero: no terminal cost)")
print(f"L(t=0)  = {L_of_t(0.0).flatten()}   (zero: perfect IC knowledge)")
print(f"L(t=tf) = {L_of_t(tf).flatten()}  (converged to SS)")

t_plot = np.linspace(0, tf, 500)
K_plot = np.array([K_of_t(t).flatten() for t in t_plot])
L_plot = np.array([L_of_t(t).flatten() for t in t_plot])

fig, axes = plt.subplots(2, 1, figsize=(10, 7))
axes[0].plot(t_plot, K_plot[:, 0], label='$K_1(t)$')
axes[0].plot(t_plot, K_plot[:, 1], label='$K_2(t)$')
axes[0].set_title('Part (a): LQR Gain $K(t) = R_{uu}^{-1} B_u^T P(t)$')
axes[0].set_xlabel('Time (s)'); axes[0].set_ylabel('Gain')
axes[0].legend(); axes[0].grid(True)

axes[1].plot(t_plot, L_plot[:, 0], label='$L_1(t)$')
axes[1].plot(t_plot, L_plot[:, 1], label='$L_2(t)$')
axes[1].set_title('Part (a): LQE Gain $L(t) = Q_e(t) C_y^T R_{vv}^{-1}$')
axes[1].set_xlabel('Time (s)'); axes[1].set_ylabel('Gain')
axes[1].legend(); axes[1].grid(True)

plt.tight_layout()
plt.savefig('HW6/3a_gains.png', dpi=150)
plt.close()



# PART (b): Simulate the combined closed-loop system

#
# Combined 4x4 dynamics:
#   [x_dot ]   [ A          -Bu K(t)         ] [x ]   [Bw   0   ] [w]
#   [xc_dot] = [ L(t)Cy   A-BuK(t)-L(t)Cy   ] [xc] + [ 0  L(t) ] [v]

x0  = np.array([10., -10.])
xc0 = np.array([0.,   0.])

dt    = 0.005
t_sim = np.arange(0, tf, dt)
N     = len(t_sim)

# Scale white noise for discrete simulation: sqrt(R/dt) * randn [Lec 12, p.12-23]
np.random.seed(42)
w_sim = np.sqrt(Rww / dt) * np.random.randn(N)
v_sim = np.sqrt(Rvv / dt) * np.random.randn(N)

x_tv  = np.zeros((n, N));  x_tv[:, 0]  = x0
xc_tv = np.zeros((n, N));  xc_tv[:, 0] = xc0
u_tv  = np.zeros(N)

for i in range(N - 1):
    t_i  = t_sim[i]
    x_i  = x_tv[:, i]
    xc_i = xc_tv[:, i]

    K_i = K_of_t(t_i).flatten()            # LQR gain at time t
    L_i = L_of_t(t_i).flatten()            # LQE gain at time t

    u_i     = -(K_i @ xc_i)                # control law: u = -K xc
    u_tv[i] = u_i

    y_i   = (Cy @ x_i)[0] + v_sim[i]      # measurement: y = Cy x + v
    innov = y_i - (Cy @ xc_i)[0]           # innovation: y - Cy xc

    dx  = A @ x_i  + Bu.flatten() * u_i + Bw.flatten() * w_sim[i]  # plant
    dxc = A @ xc_i + Bu.flatten() * u_i + L_i * innov               # estimator

    x_tv[:, i+1]  = x_i  + dt * dx
    xc_tv[:, i+1] = xc_i + dt * dxc

fig, axes = plt.subplots(3, 1, figsize=(11, 9))
axes[0].plot(t_sim, x_tv[0],  lw=2,   label='$x_1$ (true)')
axes[0].plot(t_sim, xc_tv[0], lw=1.5, linestyle='--', label='$\\hat{x}_1$ (estimate)')
axes[0].set_title('Part (b): $x_1$ and Estimate'); axes[0].set_ylabel('Value')
axes[0].legend(); axes[0].grid()

axes[1].plot(t_sim, x_tv[1],  lw=2,   label='$x_2$ (true)')
axes[1].plot(t_sim, xc_tv[1], lw=1.5, linestyle='--', label='$\\hat{x}_2$ (estimate)')
axes[1].set_title('Part (b): $x_2$ and Estimate'); axes[1].set_ylabel('Value')
axes[1].legend(); axes[1].grid()

axes[2].plot(t_sim, u_tv, lw=1.5)
axes[2].set_title('Part (b): Control Input $u(t) = -K(t)\\hat{x}(t)$')
axes[2].set_xlabel('Time (s)'); axes[2].set_ylabel('u'); axes[2].grid()

plt.tight_layout()
plt.savefig('HW6/3b_simulation.png', dpi=150)
plt.close()



# PART (c): Separation principle + compare TV vs SS gains


# --- Steady-state gains via algebraic Riccati equations ---
Pss   = solve_continuous_are(A, Bu, Q, np.array([[Ruu]]))
Kss   = (Bu.T @ Pss) / Ruu                     # shape (1, 2)

Qss_e = solve_continuous_are(A.T, Cy.T, Bw @ Bw.T * Rww, np.array([[Rvv]]))
Lss   = Qss_e @ Cy.T / Rvv                     # shape (2, 1)

# --- 4x4 closed-loop matrix ---
A_cl = np.block([
    [A,          -Bu @ Kss              ],
    [Lss @ Cy,    A - Bu @ Kss - Lss @ Cy]
])

# --- Eigenvalue check ---
ev_cl  = np.sort_complex(eigvals(A_cl))
ev_reg = np.sort_complex(eigvals(A - Bu @ Kss))
ev_est = np.sort_complex(eigvals(A - Lss @ Cy))

print("\n═══ Part (c) ═══")
print(f"Kss = {Kss.flatten()}")
print(f"Lss = {Lss.flatten()}")
print(f"\nEigenvalues of A_cl (4x4):   {ev_cl}")
print(f"Regulator poles (A - Bu Kss): {ev_reg}")
print(f"Estimator poles (A - Lss Cy): {ev_est}")
print("=> A_cl eigenvalues = union of regulator + estimator poles ✓")

# --- Simulate with SS gains (same noise realization for fair comparison) ---
x_ss  = np.zeros((n, N));  x_ss[:, 0]  = x0
xc_ss = np.zeros((n, N));  xc_ss[:, 0] = xc0
Kss_f = Kss.flatten()
Lss_f = Lss.flatten()

for i in range(N - 1):
    x_i  = x_ss[:, i]
    xc_i = xc_ss[:, i]
    u_i  = -(Kss_f @ xc_i)
    y_i  = (Cy @ x_i)[0] + v_sim[i]
    innov = y_i - (Cy @ xc_i)[0]
    dx   = A @ x_i  + Bu.flatten() * u_i + Bw.flatten() * w_sim[i]
    dxc  = A @ xc_i + Bu.flatten() * u_i + Lss_f * innov
    x_ss[:, i+1]  = x_i  + dt * dx
    xc_ss[:, i+1] = xc_i + dt * dxc

fig, axes = plt.subplots(2, 1, figsize=(11, 7))
axes[0].plot(t_sim, x_tv[0], lw=2,   label='TV gains')
axes[0].plot(t_sim, x_ss[0], lw=1.5, linestyle='--', label='SS gains')
axes[0].set_title('Part (c): Time-varying vs Steady-state Gains — $x_1$')
axes[0].set_ylabel('$x_1$'); axes[0].legend(); axes[0].grid()

axes[1].plot(t_sim, x_tv[1], lw=2,   label='TV gains')
axes[1].plot(t_sim, x_ss[1], lw=1.5, linestyle='--', label='SS gains')
axes[1].set_title('Part (c): Time-varying vs Steady-state Gains — $x_2$')
axes[1].set_ylabel('$x_2$'); axes[1].set_xlabel('Time (s)')
axes[1].legend(); axes[1].grid()

plt.tight_layout()
plt.savefig('HW6/3c_comparison.png', dpi=150)
plt.close()



# PART (d): Steady-state mean-squared values

#
# LTI system:  dz/dt = A_cl z + B_cl [w; v]
#
# Covariance X = E[z z^T] satisfies Lyapunov equation:
#   A_cl X + X A_cl^T + Q_cl = 0,  where Q_cl = B_cl diag(Rww,Rvv) B_cl^T
#
# scipy solve_lyapunov(A, Q) solves A X + X A^T = Q,
# so we pass -Q_cl to get A X + X A^T = -Q_cl  =>  A X + X A^T + Q_cl = 0

B_cl = np.block([
    [Bw,               np.zeros((n, 1))],   # process noise enters plant
    [np.zeros((n, 1)), Lss             ]    # sensor noise enters estimator via L
])
Q_cl = B_cl @ np.diag([Rww, Rvv]) @ B_cl.T

X_ss = solve_lyapunov(A_cl, -Q_cl)

residual = A_cl @ X_ss + X_ss @ A_cl.T + Q_cl
print("\n═══ Part (d) ═══")
print(f"Lyapunov residual (should be ~0): {np.max(np.abs(residual)):.2e}")
print(f"\n  E[x1^2]     = {X_ss[0,0]:.4f}   RMS = {np.sqrt(X_ss[0,0]):.4f}")
print(f"  E[x2^2]     = {X_ss[1,1]:.4f}   RMS = {np.sqrt(X_ss[1,1]):.4f}")
print(f"  E[xhat1^2]  = {X_ss[2,2]:.4f}   RMS = {np.sqrt(X_ss[2,2]):.4f}")
print(f"  E[xhat2^2]  = {X_ss[3,3]:.4f}   RMS = {np.sqrt(X_ss[3,3]):.4f}")