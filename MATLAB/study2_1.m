[x,y] = meshgrid(-3:0.1:3,-2:0.1:2);
z = (x.*x - 2.*x).*exp(-x.*x-y.*y-x.*y);
subplot(2,1,1);
mesh(x,y,z);
title('mesh函数')
subplot(2,1,2);
surf(x,y,z)
title('surf函数')
