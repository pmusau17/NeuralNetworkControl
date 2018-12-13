%% Create a neural network controller for the robot arm
clc;clear
% Load input (Desired angle)
load('input_signal_sin1.4.mat');
in = input_voltage_readings(2,:);
% Load output (Voltage)
load('encoder_reading_sin1.4.mat');
out = encoder_readings(2,:);
out = out-24.5;
% first row of each variable is the time (Ts = 0.02 seconds)

%% Define size of layers of a feedforwardnet
net = feedforwardnet([2 2],'trainbr');
% Remove processing functions
 net.inputs{1}.processFcns = {};
 net.outputs{1}.processFcns = {};
% Determine the size of inputs and outputs and ctivation functions
net.inputs{1}.size = 1; % size of inputs
net.layers{3}.size = 1; %size of outputs
net.layers{1}.transferFcn = 'purelin'; % poslin = relu
net.layers{2}.transferFcn = 'purelin'; % tansig = tanh
%net.layers{3}.transferFcn = 'poslin'; % purelin = linear
% Define the initilization of values in each layer and overall network
net.initFcn = 'initlay';
net.layers{1}.initFcn = 'initnw';
net.layers{2}.initFcn = 'initnw';
net.layers{3}.initFcn = 'initnw';

%% Train the network
net = init(net);
net = train(net,out,in);
y = net(out); 

mse = sum(abs(y.^2 - out.^2))/(length(out))

plot(out)
hold on;
plot(y)
hold off;

disp("Press any key to test yout network")
pause;

%% Test the network
% Load input (Desired angle)
load('input_signalpulse1.41050.mat');
in = input_voltage_readings(2,:);
% Load output (Voltage)
load('encoder_reading_pulse1.41050.mat');
out = encoder_readings(2,:);

y = net(out); 

mse = sum(abs(y.^2 - out.^2))/(length(out))

plot(out)
hold on;
plot(y)

%% Save network and generate simulink model
% view(net)
% save('Neural_network_controller','net'); % save net as 'Neural_network_controller
gensim(net); %generate simulink block of net




  
   
  