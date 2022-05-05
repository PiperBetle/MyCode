#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MAXN 65025
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1000007],f[1000007]={1};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)for(j=a[i];j<=MAXN;j++)
		f[j]|=f[j-a[i]];
	for(i=MAXN;i>=0;i--)if(!f[i]){ans=i;break;}
	cout<<(ans==65025?0:ans);
	
	return 0;
}
