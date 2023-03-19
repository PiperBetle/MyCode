#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
int f[200007];
inline int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		w=(w<<1)+(w<<3)+(c^48);
	return w;
}
struct people
{
	int u,v,t;
	bool operator <(const people n)const
	{
		return t>n.t;
	}
};
people a[100007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m=read(),t;
	int u,v;
	
	for(i=0;i<200007;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
	{
		a[i].u=read();
		a[i].v=read();
		a[i].t=read();
	}
	sort(a+1,a+1+m);
	for(i=1;i<=m;i++)
	{
		u=a[i].u;v=a[i].v;
		if(find(u)==find(v)||find(u+n)==find(v+n))
		{
			cout<<a[i].t<<'\n';
			return 0;
		}
		f[find(u)]=find(v+n);
		f[find(v)]=find(u+n);
	}
	cout<<"0\n";
	
	return 0;
}