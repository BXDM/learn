[x,y] = meshrid(-1:0.2:1);
z = x.^2+sin(y*pi);
[m,n] = size(z);
c = rand(m,n,3);
surf(x,y,z,c)
title('rgb')
