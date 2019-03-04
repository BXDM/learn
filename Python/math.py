import numpy as np
from scipy.linalg import solve
a = np.array([[3, 2, -7], [8, -2, -3], [4, 6, -1]])
b = np.array([-4, -5, 13])
x = solve(a, b)
print(x)