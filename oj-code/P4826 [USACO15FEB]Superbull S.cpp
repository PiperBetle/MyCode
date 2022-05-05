#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int sqr(int x){return x*x;}
struct point{int x,y;};
int f[10007],a[10007];
bool b[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	b[1]=1;
	for(i=1;i<=n;i++)
	{
		int p=1,maxn=0;
		for(j=1;j<=n;j++)if(!b[j]&&f[j]>maxn)maxn=f[j],p=j;
//		cout<<p<<' '<<f[p]<<'\n';
		b[p]=1;ans+=f[p];
		for(j=1;j<=n;j++)f[j]=max(f[j],a[p]^a[j]);
	}
	cout<<ans;
	
	return 0;
}
