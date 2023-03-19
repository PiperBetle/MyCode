#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
int a[1000007];
int n,m;
int check(int x)
{
	int cnt=0,now=0;
	for(int i=1;i<=n;i++)
	{
		now+=a[i];
		now=MAX(now,0);
		if(now>=x)
		{
			now=0;
			cnt++;
		}
	}
	return cnt;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int ans=0;
	int left=0,right=1,mid;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		right+=ABS(a[i]);
	}
	while(left+1<right)
	{
		mid=(left+right)>>1;
		if(check(mid)>=m)ans=left=mid;
		else right=mid;
	}
	if(!ans)
	{
		cout<<"-1\n";
		return 0;
	}
	left=0;
	while(left+1<right)
	{
		mid=(left+right)>>1;
		if(check(mid)==m)right=mid;
		else left=mid;
	}
	if(right>ans)
	{
		cout<<"-1\n";
		return 0;
	}
	cout<<right<<' '<<ans<<'\n';
	
	return 0;
}