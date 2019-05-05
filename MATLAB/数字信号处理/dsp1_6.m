clc;clear all
%dsp1.6
t = 0:0.001:1;
fo = 2;fl = 10;
x = chirp(t,fo,1,fl);
m = 1:length(x);
subplot(2,1,1),plot((m-1)*0.001,x)

xlim([0 1.5]),title('原始信号')
[y,n] = sigshift(x,m,500);
subplot(2,1,2),plot((n-1)*0.001,y)
xlim([0 1.5]),title('时移后信号'),xlable('时间/s')