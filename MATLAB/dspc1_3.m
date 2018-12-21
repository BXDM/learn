% dspc1_3
% 用MATLAB模拟绘制 x(n) = 2*sin(0.02*pi*n + pi/4)函数。

n = [0:100];
x = 2 * sin(0.02 * pi * n + pi/4);
stem(n,x);		%绘制火柴头图片
xlabel('n');ylabel('x(n)');title('正弦序列');
grid on;		%添加网格线
