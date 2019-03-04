x = -8:0.5:8;
y = x;
[X,Y] = meshgrid(x,y);
r = sqrt(x.^2+y.^2)+eps;
z = sin(r)./r;
mesh(X,Y,Z);
grid on