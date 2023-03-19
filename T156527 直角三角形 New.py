c=int(input())
for i in range(1,c+1,1):
    j=(c*c-i*i)**0.5
    if(j==int(j)):
        print(i,int(j))
        break
