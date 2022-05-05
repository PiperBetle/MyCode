#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
struct road
{
	int begin,end;
};
road a[10007];
inline int cmp(road _x,road _y)
{
	return _x.begin<_y.begin;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i].begin>>a[i].end;
	sort(a+1,a+1+n,cmp);
	int now=0,ans=0;
	for(i=1;i<=n;i++)
	{
		now=max(now,a[i].begin);
		while(now<a[i].end)
		{
			now+=m;
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
