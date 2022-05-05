#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define MOD 1000000000
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int find(int x)
{
	if(f[x]==x)return x;
	int fx=find(f[x]);
	d[x]^=d[f[x]];
	return f[x]=fx;
}
inline int qp(int a,int p,int t=1)
{
	for(;p;p>>=1,a=a*a%MOD)
		if(p&1)
			t=t*a%MOD;
	return t;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans;
	int x,y,flag;
	std::string data;

	cin>>n>>m;
	cout<<qp(n,m)<<'\n';

	return 0;
}