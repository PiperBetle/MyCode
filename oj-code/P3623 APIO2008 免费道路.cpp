#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using std::cin;using std::cout;
struct edge{int u,v;bool flag;};
std::vector<edge>a,b,ans;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int f[1000007];bool b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,t;
	
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>t;
		if(t==1)a.emplace_back((edge){u,v,0});
		else b.emplace_back((edge){u,v,0});
	}
	int cnt=0,num=0;
	for(i=1;i<=n;i++)f[i]=i;
	for(auto it:a)
	{
		int fx=find(it.u),fy=find(it.v);
		if(fx!=fy)f[fx]=fy,cnt++;
	}
	for(auto it:b)
	{
		int fx=find(it.u),fy=find(it.v);
		if(fx!=fy)
		{
			it.flag=1,num++,f[fx]=fy;
			if(++cnt==n-1)break;
		}
	}
	if(cnt<n-1||num>k)return cout<<"no solution",0;
	for(i=1;i<=n;i++)f[i]=i;
	cnt=0;
	for(auto it:b)
	{
		if(it.flag==0)continue;
		if(cnt>)
	}
	
	return 0;
}
