#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;
int a[1000007],n;
int s[1000007];
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
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int w,m,t;
	int x,y,c;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>s[i];
	while(m--)
	{
		cin>>c;
		if(c==1)
		{
			cin>>x>>y>>t;
			build(x,t);
			build(y+1,-t);
		}
		else
		{
			cin>>x;
			cout<<s[x]+tree_find(x)<<'\n';
		}
	}
	
	return 0;
}
