% matlab 中矢量长度问题

clear all;close all;clc;
x = 0:1:9;
y = sin(x);
n = 2*length(x);
a1 = n
yi = interpft(y,n);
a2 = n
xi = 0:0.5:9.5;
a3 = length(xi)
hold on;
plot(x,y,'ro')
plot(xi,yi,'b.-')
plot(x,sin(x),'m--')
legend('原始数据','插值后')