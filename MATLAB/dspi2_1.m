%	离散序列的傅里叶变换
%	DTTF(Discrete Time Fourier Transform)
%	Author: 百度文库

N = 8;				%原始离散信号有8个点
n = [0:1:N-1];		%原始信号是 1 行 8 列的点
xn = 0.5 .^n;		%构建原始信号为指数序列

w = [-800:1:800]*4*pi/800;		%构建频域，用 -800 到 800 取代无穷

X = xn*exp(-j*(n'*w));			%采用原始方法计算傅里叶变换

subplot(211)
stem(n,xn);
title('原始信号');
subplot(212)
plot(w/pi,abs(X));
title('DTFT变换')

