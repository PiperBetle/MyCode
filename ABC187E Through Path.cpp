#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=2e5+1;
int uu[kN],vv[kN],n,dep[kN],fa[kN],q;
long long cnt[kN];
std::basic_string<int>g[kN];
void dfs1(int u){for(int v:g[u])if(v!=fa[u])dep[v]=dep[u]+1,fa[v]=u,dfs1(v);}
void dfs2(int u){for(int v:g[u])if(v!=fa[u])cnt[v]+=cnt[u],dfs2(v);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)cin>>uu[i]>>vv[i],g[uu[i]]+=vv[i],g[vv[i]]+=uu[i];
	dep[1]=1;dfs1(1);cin>>q;
	while(q--){
		int t,id,w;cin>>t>>id>>w;
		int x=uu[id],y=vv[id];
		if(t==2)std::swap(x,y);
		if(dep[x]>dep[y])cnt[x]+=w;
		else cnt[1]+=w,cnt[y]-=w;
	}
	dfs2(1);for(int i=1;i<=n;i++)cout<<cnt[i]<<'\n';
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}