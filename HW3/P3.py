import numpy as np
import matplotlib.pyplot as plt
import control as ct

# System Matrices
A = np.array([[0, 1], 
              [0, 1]])
B = np.array([[0], 
              [1]])
Q_base = np.array([[1, 0], 
                   [0, 0]])
R_base = np.array([[1]])

# Range of ratios (Rxx/Ruu) from cheap control (big ratio) to expensive control (small ratio)
ratios = np.logspace(-3, 3, 100)

plt.figure(figsize=(8, 6))

# Calculate and plot poles for each ratio
for rho in ratios:
    # Scale Q by rho while keeping R at 1 to keep the ratio
    Q = rho * Q_base
    
    K, S, E = ct.lqr(A, B, Q, R_base)

    if rho == ratios[0]: 
        plt.plot(np.real(E), np.imag(E), 'r*', markersize=10, label='Expensive Control CL Poles')
    else:
        plt.plot(np.real(E), np.imag(E), 'b.', markersize=5)


ol_poles = np.linalg.eigvals(A)
plt.plot(np.real(ol_poles), np.imag(ol_poles), 'rx', markersize=10, markeredgewidth=2, label='Open-Loop Poles')


plt.xlabel('Real Axis')
plt.ylabel('Imaginary Axis')
plt.title('Closed-Loop Poles for Varying State and Control Gain Ratios')
plt.axhline(0, color='black', linewidth=0.5) 
plt.axvline(0, color='black', linewidth=0.5) 
plt.grid(True, linestyle='--', alpha=0.7)
plt.legend()
plt.show()