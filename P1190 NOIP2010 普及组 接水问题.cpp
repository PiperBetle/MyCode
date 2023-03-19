#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,p;

	cin>>n>>m;p=m+1;
	for(i=1;i<=n;i++)cin>>a[i];
	for(k=1;;k++)for(i=1;i<=m;i++)
	{
		if(--a[i])continue;
		if(++p<=n+1)a[i]=a[p-1];
		if(p==n+m+1)return cout<<k,0;
	}
	
	return 0;
}