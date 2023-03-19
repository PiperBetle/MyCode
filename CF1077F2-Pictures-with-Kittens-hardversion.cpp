#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int f[5007][5007],a[5007];
deque<int> q[5007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	memset(f,-0x3f,sizeof f);
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	f[0][0]=0;
	q[0].push_back(0);
	for(i=1;i<=n;i++)
		for(j=m;j>0;j--)
		{
			while(!q[j-1].empty()&&q[j-1].front()<i-k)
				q[j-1].pop_front();
			if(!q[j-1].empty())
			{
				f[i][j]=f[q[j-1].front()][j-1]+a[i];
				while(!q[j].empty()&&f[q[j].back()][j]<=f[i][j])
					q[j].pop_back();
				q[j].push_back(i);
			}
		}
	int ans=-1e15;
	for(i=n-k+1;i<=n;i++)
		ans=max(ans,f[i][m]);
	if(ans==-1e15)
		ans=-1;
	cout<<ans<<'\n';

	return 0;
}