T=int(input())
for i in range(T):
	a=int(input())
	left=0;right=1;ans=-1
	while right*right<=a:left=right;right=right<<1
	while left<=right:
		mid=(left+right)>>1
		if(mid*mid<=a):left=mid+1
		else:ans=right=mid-1
	print(ans)