import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

class CartPendulum:
    def __init__(self):
        # Physical constants
        self.M = 1.0      # Mass of cart (kg)
        self.m = 0.1      # Mass of pendulum (kg)
        self.L = 0.5      # Length to pendulum CG (m)
        self.g = 9.81     # Gravity (m/s^2)
        
        # State: [x, x_dot, theta, theta_dot]
        # theta = 0 is pointing straight down; PI is upright.
        self.state = np.array([0.0, 0.0, np.pi - 0.1, 0.0]) 

    def dynamics(self, state, force):
        """Calculates the derivatives of the state."""
        x, x_dot, theta, theta_dot = state
        
        sin_t = np.sin(theta)
        cos_t = np.cos(theta)
        
        # Denominator helper
        denominator = self.L * (self.M + self.m * sin_t**2)
        
        # Acceleration of x
        x_accel = (force + self.m * sin_t * (self.L * theta_dot**2 + self.g * cos_t)) / (self.M + self.m * sin_t**2)
        
        # Angular acceleration of theta
        theta_accel = (-force * cos_t - self.m * self.L * theta_dot**2 * sin_t * cos_t - (self.M + self.m) * self.g * sin_t) / denominator
        
        return np.array([x_dot, x_accel, theta_dot, theta_accel])

    def step(self, force, dt):
        """RK4 Integration."""
        k1 = self.dynamics(self.state, force)
        k2 = self.dynamics(self.state + 0.5 * dt * k1, force)
        k3 = self.dynamics(self.state + 0.5 * dt * k2, force)
        k4 = self.dynamics(self.state + dt * k3, force)
        
        self.state += (dt / 6.0) * (k1 + 2*k2 + 2*k3 + k4)
        return self.state

class Simulator:
    def __init__(self, system):
        self.sys = system
        self.fig, self.ax = plt.subplots(figsize=(10, 5))
        self.dt = 0.02
        
    def animate(self, frames):
        # For now, force is 0 (passive swing)
        # I think I can replace this with a controller later
        force = 0.0 
        state = self.sys.step(force, self.dt)
        
        curr_x = state[0]
        curr_theta = state[2]
        
        # Tip of the pendulum
        px = curr_x + 2 * self.sys.L * np.sin(curr_theta)
        py = -2 * self.sys.L * np.cos(curr_theta) # Offset so 0 is down
        
        self.ax.clear()
        self.ax.set_xlim([-2, 2])
        self.ax.set_ylim([-1.5, 1.5])
        self.ax.set_aspect('equal')
        
        # Draw Cart
        self.ax.add_patch(plt.Rectangle((curr_x - 0.2, -0.1), 0.4, 0.2, color='blue'))
        # Draw Pendulum
        self.ax.plot([curr_x, px], [0, py], color='red', lw=3)
        self.ax.grid(True)

    def run(self):
        ani = animation.FuncAnimation(self.fig, self.animate, frames=200, interval=20)
        plt.show()

if __name__ == "__main__":
    pendulum_system = CartPendulum()
    sim = Simulator(pendulum_system)
    sim.run()