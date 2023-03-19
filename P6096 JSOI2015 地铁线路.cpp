#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
std::unordered_map<std::string,int>map;
std::string str;
struct edge{int go,data;};
std::vector<edge>s[400007];
std::vector<int>e[400007];
std::deque<int>q;
using std::cin;using std::cout;
int dis[400007],max_l[400007],max_r[400007],f[400007],p[400007];
signed main()
{
//	freopen("home.in","r",stdin);
//	freopen("home.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m,l=1,r=0;
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>str,map[str]=i;
	for(i=1;i<=n;i++)for(e[i].emplace_back(0),cin>>k;k>=1;k--)
		cin>>str,e[i].emplace_back(map[str]),
		s[map[str]].emplace_back(edge{i+m,1}),s[i+m].emplace_back(edge{map[str],0});
	cin>>str;int start=map[str];
	cin>>str;int end=map[str];
	memset(dis,0x3f,sizeof dis);
	dis[start]=0;q.push_back(start);
	while(!q.empty()){
		int u=q.front();q.pop_front();
		for(auto v:s[u])if(dis[v.go]==0x3f3f3f3f){
			if(v.data)dis[v.go]=dis[u]+1,q.push_back(v.go);
			else dis[v.go]=dis[u],q.push_front(v.go);
		}
	}
	if(dis[end]==0x3f3f3f3f)return cout<<"-1\n0",0;
	for(i=1;i<=n;i++)p[i]=i;
	std::sort(p+1,p+n+1,[&](int x,int y){return dis[x+m]<dis[y+m];});
	for(k=1;k<=n;k++,l=r+1){
		while(r<n&&dis[p[r+1]+m]==k)r++;
		for(i=l;i<=r;i++){
			for(j=0;j<=(int)e[p[i]].size();j++)max_l[j]=max_r[j]=-0x3f3f3f3f;
			for(j=1;j<(int)e[p[i]].size();j++)if(dis[e[p[i]][j]]==k-1)max_l[j]=max_r[j]=f[e[p[i]][j]];
			for(j=1;j<(int)e[p[i]].size();j++)max_l[j]=std::max(max_l[j],max_l[j-1]+1);
			for(j=(int)e[p[i]].size()-1;j>=1;j--)max_r[j]=std::max(max_r[j],max_r[j+1]+1);
			for(j=1;j<(int)e[p[i]].size();j++)if(dis[e[p[i]][j]]==k)f[e[p[i]][j]]=std::max(f[e[p[i]][j]],std::max(max_l[j],max_r[j]));
		}
	}
	cout<<dis[end]<<'\n'<<f[end];
	return 0;
}