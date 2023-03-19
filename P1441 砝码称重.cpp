#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define MOD 1000000007
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[107],n,m,ans;
bool b[107],f[107];
void dfs(int res,int now)
{
	cout<<res<<' '<<now<<' '<<ans<<'\n';
	if(res>n||now>m)return;
	if(res==n&&now==m)
	{
		memset(f,0,sizeof f);
		f[0]=1;int cnt=0,num=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i])continue;
			for(int j=num;j>=0;j--)
				if(f[j]&&!f[j+a[i]])cnt++,f[j+a[i]]=1;
			num+=a[i];
		}
		ans=max(ans,cnt);
		return;
	}
	dfs(res+1,now);
	b[res]=1;
	dfs(res+1,now+1);
	b[res]=0;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;

	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	dfs(1,1);
	cout<<ans<<'\n';
	
	return 0;
}