# import sys
# sys.stdin=open('equal.in','r')
# sys.stdout=open('equal.out','w')
lis='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ans=input()
ans=ans.replace(' ','')
ans=ans.replace('^','**')
a=2
ans=int(eval(ans))
n=int(input())
cnt=0
s=""
for i in range(n):
	t=input()
	t=t.replace(' ','')
	t=t.replace('^','**')
	t=int(eval(t))
	if t==ans :
		s=s+str(lis[i])
print(s)