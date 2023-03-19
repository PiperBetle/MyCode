#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int a[1000007],n;
inline int lowbit(int _x)
{
	return _x&(-_x);
}
inline void build(int _x,int _k)
{
	for(;_x<=n;_x+=lowbit(_x))
		a[_x]+=_k;
}
inline int tree_find(int _x)
{
	int _sum=0;
	for(;_x;_x-=lowbit(_x))
		_sum+=a[_x];
	return _sum;
}
inline int tree_sum(int left,int right)
{
	return tree_find(right)-tree_find(left-1);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int w,m,t;
	int x,y,c;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		build(i,k);
	}
	while(m--)
	{
		cin>>c>>x>>y;
		if(c==1)
			build(x,y);
		else
			cout<<tree_sum(x,y)<<'\n';
	}
	
	return 0;
}
