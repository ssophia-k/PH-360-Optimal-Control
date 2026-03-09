from scipy.optimize import fsolve
from scipy.linalg import solve_discrete_are
import numpy as np

def equations(vars):
    p11, p12, p21, p22 = vars
    eq1 = (p11+1)*(p22-1) - p11 + p12*p21
    eq2 = (p11+1)*(p12-p22+1) - p21 + p21*p22
    eq3 = (p11+1)*(p21-p22+1) - p12 - p12*p11
    eq4 = (p11+1)*(p11-p21-p12+p22-2) - p22 - p22*p11
    return [eq1, eq2, eq3, eq4]

initial_guess = [0.5, 0.5, 0.5, 0.5]
solution = fsolve(equations, initial_guess)
p11, p12, p21, p22 = solution
print(f"p11: {p11}, p12: {p12}, p21: {p21}, p22: {p22}")

# Define matrices from your problem
A = np.array([[1, 1], 
              [1, 0]])

B = np.array([[1], 
              [0]])

Q = np.array([[1, 0], 
              [0, 1]])

R = np.array([[1]])

# Solve the Discrete Algebraic Riccati Equation (DARE)
# This solves: P = A'PA - A'PB(R + B'PB)^-1 B'PA + Q
Pss = solve_discrete_are(A, B, Q, R)

print("Steady State P matrix:")
print(Pss)

# To verify Equation (2) - the "cleaner" form
# Pss = Q + A' * Pss * inv(I + B * inv(R) * B' * Pss) * A
I = np.eye(2)
inv_term = np.linalg.inv(I + B @ np.linalg.inv(R) @ B.T @ Pss)
Pss_check = Q + A.T @ Pss @ inv_term @ A

print("\nVerification of 'Cleaner Form' (Equation 2):")
print(Pss_check)