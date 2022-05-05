n,m=input().split()
n=int(n)
m=int(m)
n=m-n
a=[1,2]
for i in range(3,n+1,1):
    y=a.pop()
    x=a.pop()
    x=x+y
    a.append(y)
    a.append(x)
print(a.pop())
