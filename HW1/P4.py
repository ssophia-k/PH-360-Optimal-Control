import numpy as np
from scipy.optimize import minimize
import matplotlib.pyplot as plt

# Define the objective function
def objective(vars):
    x, y = vars
    return x**2 + y**2 - 6*x*y - 4*x - 5*y

# Define the constraints in the form g(x) >= 0
cons = (
    {'type': 'ineq', 'fun': lambda vars: -2*vars[0] + vars[1] + 1},   # f1
    {'type': 'ineq', 'fun': lambda vars: -(vars[0] + vars[1] - 4)},  # f2 (flipped for >= 0)
    {'type': 'ineq', 'fun': lambda vars: vars[0] + 1}                # f3
)

# Initial guess
x0 = [0, 0]

# Solve Part A
res_a = minimize(objective, x0, constraints=cons)

# Solve Part B (Change f1 constant to 1.1)
cons_b = (
    {'type': 'ineq', 'fun': lambda vars: -2*vars[0] + vars[1] + 1.1},
    {'type': 'ineq', 'fun': lambda vars: -(vars[0] + vars[1] - 4)},
    {'type': 'ineq', 'fun': lambda vars: vars[0] + 1}
)
res_b = minimize(objective, x0, constraints=cons_b)

print(f"Part (a) Optimal Point: x={res_a.x[0]:.4f}, y={res_a.x[1]:.4f}")
print(f"Part (a) Optimal Cost:  {res_a.fun:.4f}")
print("-" * 30)
print(f"Part (b) New Optimal Cost: {res_b.fun:.4f}")
print(f"Difference: {res_b.fun - res_a.fun:.4f}")




# Define grid
x = np.linspace(-2, 4, 400)
y = np.linspace(-2, 5, 400)
X, Y = np.meshgrid(x, y)
Z = X**2 + Y**2 - 6*X*Y - 4*X - 5*Y

# Boundaries
y1 = 2*x - 1  # f1: -2x + y + 1 = 0
y2 = 4 - x    # f2: x + y - 4 = 0

plt.figure(figsize=(10, 8))
cp = plt.contour(X, Y, Z, levels=50, cmap='RdYlBu_r')
plt.clabel(cp, inline=1, fontsize=8)

# Feasible Region
plt.imshow(((-2*X + Y + 1 >= 0) & (X + Y - 4 <= 0) & (X >= -1)).astype(int), 
           extent=(x.min(), x.max(), y.min(), y.max()), origin="lower", alpha=0.1, cmap='Greens')

plt.plot(x, y1, 'b--', label='f1 (Active)')
plt.plot(x, y2, 'g--', label='f2 (Active)')
plt.axvline(-1, color='r', linestyle='--', label='f3 (Inactive)')
plt.plot(1.6667, 2.3333, 'ko', label='Actual Optimum')

plt.title('Optimization Landscape')
plt.legend()
plt.show()
