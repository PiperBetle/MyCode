#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=2e5+1,MOD=998244353;
inline int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
int fa[kN],sz[kN],ed[kN],n,m,ans=1;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))==(y=find(y)))ed[x]++;else fa[x]=y,sz[y]+=sz[x],ed[y]+=ed[x];}
signed main(){
//	freopen(".in","r",stdin);4
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=ed[i]=1;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,merge(u,v);
	for(int i=1;i<=n;i++)if(find(i)==i){
		if(sz[i]+1==ed[i])add1(ans,ans);else return cout<<0,0;
	}
	cout<<ans;
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}