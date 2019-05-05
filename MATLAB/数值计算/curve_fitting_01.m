x = [-2,-1,0,1,2];
y = [-0.1,-0.1,0.4,0.9,1.6];
A = polyfit(x,y,2)
B = polyfit(x,y,3)
% a = A(1),b = A(2),c = A(2),D
x1 = -10:0.01:10;y1 = polyval(A,x1);y2 = polyval(B,x1);
plot(x1,y1,x,y,'o',x1,y2,'--')
% gtext(datestr(today))		插入日期