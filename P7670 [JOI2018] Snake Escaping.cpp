//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
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
constexpr int N=1<<20|1;
int n,q,f[N],g[N],ans,p1,p2;
bsc s,t;
bsi b0,b1,b2;
void dfs0(int u,int msk,int fl){
	if(u==siz(b0)){ans+=g[msk]*fl;return;}
	dfs0(u+1,msk,fl);dfs0(u+1,msk|(1<<b0[u]),-fl);
}
void dfs1(int u,int msk,int fl){
	if(u==siz(b1)){ans+=f[msk]*fl;return;}
	dfs1(u+1,msk,fl);dfs1(u+1,msk^(1<<b1[u]),-fl);
}
void dfs2(int u,int msk){
	if(u==siz(b2)){ans+=s[msk];return;}
	dfs2(u+1,msk);dfs2(u+1,msk|(1<<b2[u]));
}
signed main(){
//	freopen("nanaqimi.in","r",stdin);
//	freopen("nanaqimi.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q>>s;
	for(int i=0;i<(1<<n);i++)f[i]=g[i]=s[i]-='0';
	for(int j=0;j<n;j++)for(int i=0;i<(1<<n);i++)
		if(i>>j&1)f[i]+=f[i^(1<<j)];
		else g[i]+=g[i^(1<<j)];
	while(q--){
		cin>>t;t=' '+t;ans=p1=p2=0;
		b0=0;b1=0;b2=0;
		for(int i=1;i<=n;i++)switch(t[i]){
		case '0':b0+=n-i;break;
		case '1':b1+=n-i;p1|=1<<(n-i);break;
		case '?':b2+=n-i;p2|=1<<(n-i);break;
		}
		if(siz(b0)<=min(siz(b1),siz(b2)))dfs0(1,p1,1);
		else if(siz(b1)<=min(siz(b0),siz(b2)))dfs1(1,p1|p2,1);
		else dfs2(1,p1);
		cout<<ans<<'\n';
	}
	return 0;
}