#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
std::string s;
int n,m,fa[N],sz[N],gs[N],top[N],dep[N];
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])std::swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>s>>m;n=siz(s);s=' '+s;
	for(int i=2,j=0;i<siz(s);i++){
		while(j&&s[i]!=s[j+1])j=fa[j];
		fa[i]=j+=s[i]==s[j+1];
	}
	for(int i=n;i>=1;i--){
		sz[i]++;
		if(fa[i])sz[fa[i]]+=sz[i];
		if(sz[i]>=sz[gs[fa[i]]])gs[fa[i]]=i;
	}
	for(int i=1;i<=n;i++){
		dep[i]=dep[fa[i]]+1;
		if(gs[fa[i]]!=i)top[i]=i;
		else top[i]=top[fa[i]];
	}
	for(int x,y;m--;){
		cin>>x>>y;
		cout<<LCA(fa[x],fa[y])<<'\n';
	}
	return 0;
}