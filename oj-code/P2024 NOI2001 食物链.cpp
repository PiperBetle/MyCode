#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[300007],a[300007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,ans=0;

	for(i=0;i<300007;i++)f[i]=i;
	cin>>n>>m;
	while(m--)
	{
		cin>>t>>x>>y;
		if(x>n||y>n){ans++;continue;}
		if(t==1)
			if(find(x+n)==find(y)||find(x)==find(y+n))ans++;
			else{f[find(x)]=find(y);f[find(x+n)]=find(y+n);f[find(x+(n<<1))]=find(y+(n<<1));}
		else
			if(find(x)==find(y)||find(x)==find(y+n))ans++;
			else{f[find(x+n)]=find(y);f[find(x+(n<<1))]=find(y+n);f[find(x)]=find(y+(n<<1));}
	}
	cout<<ans<<'\n';
	
	return 0;
}