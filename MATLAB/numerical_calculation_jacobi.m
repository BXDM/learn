fuction[x,n] = jacobi(A,b,x0,eps,varargin)
if nargin ==3
	eps = 1.0e-6;
	M = 200;
elseif nargin<3
	error
	return
elseif nargin ==5
	M =vargin{1};
end
D = diag(diag(A));
L = -tril(A,-1);
U = -triu(A,1);
B = D\(L+U);
f = D\b;
x = B*x0+f;
n = 1;
while norm(x-x0)>=eps
	x0 = x;
	x = B*x0+f;
	n = n+1;
	if(n >= M)
		disp("warning:迭代次数太多");
		return;
	end
end
