def pow(x):
	mul=1
	for i in range(x):
		mul*=(i+1)
	return mul
def binum(n,m):
	if n<m:
		return 1
	return pow(n)//pow(m)//pow(n-m)
n,k,p=map(int,input('').split())
k-=1
if k>n-3:
	print(0)
else:
	print((binum(n-3,k)*binum(n+k-1,k)//(k+1))%p)