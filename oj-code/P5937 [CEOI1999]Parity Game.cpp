#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::map<int,int>f,d;
inline int find(int x)
{
	if(!f.count(x))f[x]=x;
	if(f[x]==x)return x;
	int fx=find(f[x]);
	d[x]^=d[f[x]];
	return f[x]=fx;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans;
	int x,y,flag;
	std::string data;

	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>data;
		flag=(data!="even");
		int fx=find(x-1),fy=find(y);
		if(fx==fy){if(flag!=(d[x-1]^d[y]))return cout<<i-1<<'\n',0;}
		else{f[fx]=fy;d[fx]=flag^d[x-1]^d[y];}
	}
	cout<<m<<'\n';

	return 0;
}
