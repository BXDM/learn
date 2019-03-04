from scipy import linalg
import numpy as np
 
# 3x_1+2x_2=5
# x_1+x_2=2
A=np.array([[3,2],[1,1]])
B=np.array([5,2])
x=linalg.solve(A,B)
print(x)