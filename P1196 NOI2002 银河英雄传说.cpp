#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline auto max(auto x,auto y){return x>y?x:y;}
inline auto min(auto x,auto y){return x<y?x:y;}
inline auto abs(auto x){return x>0?x:-x;}
int f[300007],sum[300007],b[300007];
inline int find(int x)
{
	if(f[x]==x)return x;
	int fa=find(f[x]);
	sum[x]+=sum[f[x]];
	return f[x]=fa;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	char c;
	int x,y;
	
	for(i=0;i<300007;i++)
		f[i]=i,b[i]=1;
	std::cin>>T;
	while(T--)
	{
		std::cin>>c>>x>>y;
		if(c=='M')
		{
			int fx=find(x),fy=find(y);
			f[fx]=fy;
			sum[fx]+=b[fy];
			b[fy]+=b[fx];
		}
		if(c=='C')
		{
			int fx=find(x),fy=find(y);
			if(fx!=fy)
				std::cout<<"-1\n";
			else
				std::cout<<abs(sum[x]-sum[y])-1<<'\n';
		}
	}

	return 0;
}