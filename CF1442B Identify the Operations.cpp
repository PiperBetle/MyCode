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
constexpr int N=2e5+2,MOD=998244353;
int n,m,ans,a[N],b[N],pre[N],nxt[N];
bool vis[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;ans=1;
		memset(pre+1,0,sizeof(int)*n);
		memset(nxt+1,0,sizeof(int)*n);
		memset(vis+1,0,sizeof(bool)*n);
		vis[0]=vis[n+1]=true;a[0]=a[n+1]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i],vis[b[i]]=true;
		for(int i=1;i<=n;i++)pre[a[i]]=a[i-1],nxt[a[i]]=a[i+1];
		for(int i=1;i<=m;i++){
			bool f1=vis[pre[b[i]]],f2=vis[nxt[b[i]]];
			if(f1&&f2){ans=0;break;}
			if(!f1&&!f2){if((ans+=ans)>=MOD)ans-=MOD;}
			vis[b[i]]=false;
		}
		cout<<ans<<'\n';
	}
	return 0;
}