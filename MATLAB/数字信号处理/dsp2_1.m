%   dsp2_0;
%   fourier transform
%   author:北巷的猫
%   data 2018.11.18

clc;clear all;
x = linspace(-2*pi,2*pi,100);
a1 = length(x)
w = linspace(0,10,100);
a2 = length(w)

y1 = sin(x);
y2 = fft(y1);
a3 = length(y2)
y3 = sin(x)+cos(2.*x);
y4 = fft(y3);
a4 = length(y4)

subplot(2,2,1);plot(x,y1)
title('y = sin(x)')
xlabel('t')
subplot(2,2,2);plot(w,real(y2))
title('频率域')
xlabel('f')
subplot(2,2,3);plot(x,y3)
title('y = sin(x)+cos(2*x)')
xlabel('t')
subplot(2,2,4);plot(w,real(y4))
title('频率域')
xlabel('f')

suptitle('傅里叶变换')