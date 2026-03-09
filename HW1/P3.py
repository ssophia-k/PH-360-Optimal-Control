import numpy as np
from scipy.optimize import minimize

def F(x):
    return x[0]**2 + x[1]**2 + x[2]**2 - x[0]*x[1] - x[1]*x[2] - 2*x[0] - 8*x[2]

def grad_F(x):
    df_dx1 = 2*x[0] - x[1] - 2
    df_dx2 = 2*x[1] - x[0] - x[2]
    df_dx3 = 2*x[2] - x[1] - 8
    return np.array([df_dx1, df_dx2, df_dx3])

def steepest_descent(alpha, x0, tol=1e-6, max_iter=10000):
    x = x0.copy()
    for i in range(max_iter):
        grad = grad_F(x)
        if np.linalg.norm(grad) < tol:
            return x, i
        x = x - alpha * grad
    return x, max_iter

# Parameters
x0 = np.array([1.0, 1.0, 1.0])
alphas = [0.1, 0.2, 0.5, 1.0]

print("--- Steepest Descent Results ---")
for a in alphas:
    res, iterations = steepest_descent(a, x0)
    print(f"Alpha: {a:<4} | Iterations: {iterations:<5} | Final x: {res}")

# Part (d): Comparison with scipy.optimize (fminunc equivalent)
res_scipy = minimize(F, x0, method='BFGS', tol=1e-6)
print("\n--- Scipy (fminunc equivalent) ---")
print(f"Iterations: {res_scipy.nit}")
print(f"Final x: {res_scipy.x}")