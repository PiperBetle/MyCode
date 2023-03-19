def main():
	a=int(input());b=int(input())
	left=0;right=1;ans=-1
	while right**a<=b:left=right;right=right<<1
	while left<=right:
		mid=(left+right)>>1
		if(mid**a<=b):left=mid+1
		else:ans=right=mid-1
	print(ans)
main()