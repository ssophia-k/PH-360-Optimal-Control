% Load model parameters
motor_params;

%A = [0 0 1 0;
 %   0 0 0 1;
  %  0 (mp^2*l^2*r*g)/Jt (-Jp * br)/Jt (mp*r*bp*l)/Jt;
  % 0 (-mp*g*l*Jr)/Jt (mp*l*r*br)/Jt (-Jp*bp)/Jt];

%B = [0; 0; Jp/Jt; -mp*r*l/Jt];

% State Space Representation
A = [0 0 1 0;
     0 0 0 1;
     0 mp^2*l^2*r*g/Jt  -br*Jp/Jt   -mp*l*r*bp/Jt 
     0  mp*g*l*Jr/Jt    -mp*l*r*br/Jt   -Jp*bp/Jt];

B = [0; 0; Jp/Jt; mp*l*r/Jt];
C = eye(2,4);
D = zeros(2,1);


% Add actuator dynamics
A(3,3) = A(3,3) - km*km/Rm*B(3);
A(4,3) = A(4,3) - km*km/Rm*B(4);
B = km * B / Rm;

controllability = horzcat(B, A*B, A^2*B, A^3*B);

control_rank = rank(controllability); % it is 4, good.

Q = diag([5,0.5,0.25,0.25]);
% Q = diag([0.25,0.5,0.25,0.25]);

n = size(A,1);
m = size(B,2);
p = size(C,1);
R = blkdiag(eye(m), -eye(p));
B2 = [B, zeros(n,p)];
S = [zeros(n,m), C'];

[X,K,L, info] = icare(A,B2,Q,R,S,[],[]);

K_new = K(1,:);


