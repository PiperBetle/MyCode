def qp(a,b):
	t=1
	while b!=0:
		if b%2==1:
			t=t*a%1000
		b//=2
		a=a*a%1000
	return t
n,k=map(int,input().split())
k=qp(k,k)
fac=[0]*1001
fac[0]=1
for i in range(1,1001):
	fac[i]=fac[i-1]*i
if k<n:
	print(0)
else:
	n-=1
	k-=1
	print(fac[k]//fac[n]//fac[k-n])