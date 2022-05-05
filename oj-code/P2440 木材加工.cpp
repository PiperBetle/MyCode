#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1000007];
bool check(int x,int n,int k)
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i]/x;
	return sum>=k;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int sum=0;
	int left=1,right=-1,mid;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		right=max(right,a[i]);
	}
	if(sum<m)
	{
		cout<<0;
		return 0;
	}
	while(left+1<right)
	{
//		cout<<left<<" "<<right<<endl;
		mid=(left+right)>>1;
		if(check(mid,n,m))
			left=mid;
		else
			right=mid;
	}
	cout<<left;
	
    return 0;
}
