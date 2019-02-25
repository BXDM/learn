import numpy as np
from enthought.mayavi import mlab
x,y=np.ogrid [-2:2:160j,-2:2:160j]
z=abs(x)*np.exp(-x**2-(y/.75)**2)
pl=mlab.surf(x,y,z,warp_scale=2)
mlab.axes(xlabel='x',ylabel='y',zlabel='z')
mlab.outline(pl)
mlab.show()