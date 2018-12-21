%指数信号
% 上课文件 用MATLAB中的stem函数绘出0.5exp(n)序列，n从0到10。
% dsoc1_0
clc;clear all

n = [0:10];			%给出序号序列
x = (0.5).^n;		%给出值序列
stem(n,x)
xlabel('n'),ylabel('x(n');title('实指数序列');
grid on;		%添加网格
