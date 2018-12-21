clc,clear all,close all
X = -10:0.1:10;
Y = -10:0.1:10;
[X,Y] = meshgrid(X,Y);
Z = X.*X+2*Y+3;
surf(X,Y,Z);