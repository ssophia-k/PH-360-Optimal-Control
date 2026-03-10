import numpy as np
import matplotlib.pyplot as plt

t = np.linspace(0, 1, 100)

c1 = 16 / (np.exp(4) - 1)
c2 = 2 * np.exp(4) / (np.exp(4) - 1)

u_opt = -0.5 * c1 * np.exp(2 * t)
x_opt = -(1/8) * c1 * np.exp(2 * t) + c2 * np.exp(-2 * t)

plt.figure(figsize=(8, 6))

plt.subplot(2, 1, 1)
plt.plot(t, x_opt, 'b-', linewidth=2)
plt.title('Optimal State Trajectory x(t)')
plt.xlabel('Time (t)')
plt.ylabel('State x(t)')
plt.grid(True, linestyle='--', alpha=0.7)

plt.subplot(2, 1, 2)
plt.plot(t, u_opt, 'r-', linewidth=2)
plt.title('Optimal Control Input u(t)')
plt.xlabel('Time (t)')
plt.ylabel('Control u(t)')
plt.grid(True, linestyle='--', alpha=0.7)

plt.tight_layout()
plt.show()