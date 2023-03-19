c=int(input())
flag=0
for i in range(1,c+1,1):
    for j in range(i,int((c*c-i*i)**0.5)+1,1):
        if(i*i+j*j==c*c):
            print(i,j)
            flag=1
        if(flag==1):
            break
    if(flag==1):
        break
