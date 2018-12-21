% dspc1_4
% 阶跃信号

n0 = 0;
n1 = -10;
n2  = 10
n = [n1:n2];
x = [(n - n0) > 0];
% 当只有当n - n0 >= 0时值才为1，否则为0
stem(n,x)
xlabel('n');ylabel('x(n)');title('阶跃序列');
grid on;