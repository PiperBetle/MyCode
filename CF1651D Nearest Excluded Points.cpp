//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<map>
#include<queue>
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
constexpr int N=2e5+1,dx[]={-1,1,0,0},dy[]={0,0,-1,1};
std::map<pii,int>mp;
int n;
bool vis[N];
pii a[N],b[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,mp[a[i]]=i;
	for(int i=1;i<=n;i++)for(int j=0;j<4;j++)if(!mp.count({a[i].fi+dx[j],a[i].se+dy[j]}))
		b[i]={a[i].fi+dx[j],a[i].se+dy[j]},vis[i]=true,q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int j=0;j<4;j++)if(mp.count({a[u].fi+dx[j],a[u].se+dy[j]})){
			int v=mp[{a[u].fi+dx[j],a[u].se+dy[j]}];
			if(!vis[v])b[v]=b[u],vis[v]=true,q.push(v);
		}
	}
	for(int i=1;i<=n;i++)cout<<b[i].fi<<' '<<b[i].se<<'\n';
	return 0;
}