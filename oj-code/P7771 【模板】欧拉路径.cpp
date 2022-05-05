#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
std::vector<int>s[1000007];
int _i[1000007],_o[1000007];
void dfs(int now)
{
	int i,len=s[now].size();
	for(i=0;i<len;i)
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int u,v,start=1;
	int begin,end,cnt=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		s[u].emplace_back(v);
		_o[u]++;
		_i[v]++;
	}
	for(i=1;i<=n;i++)if(_i[i]!=_o[i])
	{
		cnt++;
		if(_i[i]+1==_o[i])begin=i;
		if(_i[i]==_o[i]+1)end=i;
	}
	if(!cnt)begin=end=1;
	if(cnt>2||!begin||!end)return cout<<"No",0;
	for(i=1;i<=n;i++)std::sort(s[i].begin(),s[i].end());

	return 0;
}