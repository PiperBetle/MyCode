#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
char a[1000007];
bool b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int m,T;
	
	scanf("%s",a+1);
	int left=1,right=strlen(a+1),n=right,sum=0;
	for(;;)
	{
		if(left>right)break;
		if(a[left]==a[right])
		{
			b[left]=b[right]=1;
			sum+=1+(left!=right);
		}
		else if(left+1<=right&&a[left+1]==a[right])
		{
			b[left+1]=b[right]=1;
			sum+=1+(left+1!=right);
			left++;
		}
		else if(left<=right-1&&a[left]==a[right-1])
		{
			b[left]=b[right-1]=1;
			sum+=1+(left!=right-1);
			right--;
		}
		left++;
		right--;
	}
	if(sum<n/2)puts("IMPOSSIBLE");
	else
		for(i=1;i<=n;i++)
			if(b[i])cout<<a[i];
	
	return 0;
}
