% 正弦信号
%dspc1_2
n = [0:100];
x = 2*sin(0.02*pi*n+pi/4);
stem(n,x)
xlable('n');ylabel('x(n)');title('正弦信号');
grid on;
