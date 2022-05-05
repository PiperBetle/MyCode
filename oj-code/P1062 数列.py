m,n=input().split()
n=int(n)
m=int(m)
a=[]
la=0
ans=0
while True:
    a.append(n%2)
    n=n//2
    la=la+1
    if(n==0):
        break
for i in range(0,la):
    ans=ans*m+a.pop()
print(ans)
