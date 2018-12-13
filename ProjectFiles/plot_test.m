clc; clear all;
load('input_signal.mat')
load('encoder_reading.mat')

t = encoder_readings(1,:);
enc = encoder_readings(2,:);
inp = input_voltage_readings(2,:);

plot(t,enc,t,inp)