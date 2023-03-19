#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int f[1007],b[1007];
using namespace std;
inline int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x,y,ans=-1,cnt=0;
	
	for(i=0;i<1007;i++)
		f[i]=i;
	cin>>n>>k;
	while(k--)
	{
		cin>>x>>y;
		if(find(x)!=find(y))
			f[find(x)]=find(y);
	}
	for(i=1;i<=n;i++)
	{
		if(find(i)==i)
			cnt++;
		b[find(i)]++;
	}
	for(i=1;i<=n;i++)
		ans=max(ans,b[i]);
	cout<<cnt<<" "<<ans<<'\n';
	
	return 0;
}