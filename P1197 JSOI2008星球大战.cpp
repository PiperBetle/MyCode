#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
int f[400007],die[400007],db[400007],ans[400007];
vector<int> s[400007];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m;
	for(i=0;i<400007;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		s[u].push_back(v);
		s[v].push_back(u);
	}
	cin>>k;
	for(i=1;i<=k;i++)
	{
		cin>>die[i];
		db[die[i]]=1;
	}
	for(i=0;i<400007;i++)
	{
		if(db[i])continue;
		for(j=0;j<s[i].size();j++)
		{
			if(db[s[i][j]])continue;
			int fx=find(i);
			int fy=find(s[i][j]);
			if(fx!=fy)
			{
				f[fx]=fy;
			}
		}
	}
	for(i=0;i<n;i++)
		ans[k+1]+=(!db[i]&&f[i]==i);
	int cnt=ans[k+1];
	for(i=k;i>=1;i--)
	{
		db[die[i]]=0;
		cnt++;
		for(j=0;j<s[die[i]].size();j++)
		{
			if(db[s[die[i]][j]])continue;
			int fx=find(die[i]);
			int fy=find(s[die[i]][j]);
			// cout<<die[i]<<" "<<s[die[i]][j]<<endl;
			if(fx!=fy)
			{
				f[fx]=fy;
				cnt--;
			}
		}
		ans[i]=cnt;
	}
	for(j=1;j<=k+1;j++)
		cout<<ans[j]<<'\n';

	return 0;
}