#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[10007];
inline char dfs(int pos,int now)
{
	if(!now)
		if(pos==1)return 'm';
		else return 'o';
	if(pos<=a[now-1])return dfs(pos,now-1);
	if(pos>a[now]-a[now-1])return dfs(pos-a[now]+a[now-1],now-1);
	if(pos==a[now-1]+1)return 'm';
	return 'o';
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,cnt=0;
	
	cin>>n;
	a[0]=3;
	for(i=1;a[i-1]<n;i++)
		a[i]=(a[i-1]<<1)+i+3;
	cout<<dfs(n,i-1)<<'\n';
	
	return 0;
}