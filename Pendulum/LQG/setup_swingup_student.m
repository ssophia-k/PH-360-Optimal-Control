% Load model parameters
qube2_rotpen_param;
% Moment of inertia of pendulum about center of mass (kg-m^2)
Jp_cm = mp*Lp^2/12; % used to calculate pendulum energy in swing-up control
%