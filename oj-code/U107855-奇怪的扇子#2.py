n,a,b=map(float,input().split())
a0=a*a*b/2.0
d=b*b*b/2.0
ans=n*a0+n*(n-1)*d/2.0
print("%.6f"%ans)