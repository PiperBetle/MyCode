#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
int n,m,s,fa[N],rt[N];
bsi g[N];
void dfs(int u,int f,int r){
	if(rt[u]==r)return;
	if(fa[u]){
		int p1=u,p2=f;
		bsi s1,s2={p1};
		while(p1)s1+=p1,p1=fa[p1];
		while(p2)s2+=p2,p2=fa[p2];
		cout<<"Possible\n"<<siz(s1)<<'\n';
		for(int i=siz(s1)-1;~i;i--)cout<<s1[i]<<' ';
		cout<<'\n'<<siz(s2)<<'\n';
		for(int i=siz(s2)-1;~i;i--)cout<<s2[i]<<' ';
		exit(0);
	}
	rt[u]=r;fa[u]=f;
	for(int v:g[u])dfs(v,u,r);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>s;
	for(int u,v;m--;){cin>>u>>v;if(v!=s)g[u]+=v;}
	for(int v:g[s])dfs(v,s,v);
	cout<<"Impossible";
	return 0;
}