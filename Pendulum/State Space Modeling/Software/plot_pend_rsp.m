%% Setup variables
% Load from variables set in workspace after running a Simulink model or
% from the previously saved response saved in the MAT files above.
t = data_vm(:,1);
u = data_vm(:,2);
arm_meas = data_theta(:,2);
arm_sim = data_theta(:,3);
pend_meas = data_alpha(:,2);
pend_sim = data_alpha(:,3);
%
%% Plot response
subplot(2,1,1);
plot(t,arm_meas,'r-',t,arm_sim,'b--');
ylabel('Rotary Arm (rad)');
legend('Measured', 'Simulated');
%
subplot(2,1,2);
plot(t,pend_meas,'r-',t,pend_sim,'b--');
ylabel('Pendulum (rad)');
xlabel('Time (s)');
legend('Measured', 'Simulated');
%
%% Print
% print rsp_rotpen_ss_model_val.png -dpng -r300