n,t=input().split()
s=int(input())
f=[[0 for i in range(0,107)]for j in range(0,107)]
for i in range(0,n,1):
    f[0][i]=int(str(s)[0:i+1])
for i in range(1,t+1,1):
    for j in range(1,n+1,1):
        for k in range(i,j+1,1):
            f[i][j]=max(f[i][j],f[i-1][k-1]*int(str(s)[k:j+1]))
print(f[t][n-1])
