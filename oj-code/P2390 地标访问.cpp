#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
int n,m,ans=0;
int check(int right)
{
	for(i=right;i<=n;i++)
	{
		int left=i-right+1;
		if((a[right]<=0)&&(-a[left]<=m))return 1;
		if((a[left]>=0)&&(a[right]<=m))return 1;
		if(a[l]<=0&&a[i]>=0)&&
			if(min(-a[l],a[i])+(a[i]-a[l])<=t)return 1;
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int left=-1,right=n+1;
	while(left+1<right)
	{
		int mid=(left+right)/2;
		if()
	}
	
    return 0;
}
