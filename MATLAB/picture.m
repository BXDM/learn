x = -8:0.5:8;
y = x;
[X,Y] = meshgrid(x,y);
R = sqrt(X.^2+Y.^2)+eps;
Z = sin(R);
mesh(X,Y,Z);
grid on
