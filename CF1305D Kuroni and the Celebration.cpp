//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
constexpr int N=1001;
int n,deg[N];
bsi g[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u,deg[u]++,deg[v]++;
	for(int i=1;i<=n;i++)if(deg[i]==1)q.push(i);
	for(int i=1,x,y,z;i<=n/2;i++){
		x=q.front();q.pop();
		y=q.front();q.pop();
		cout<<"? "<<x<<' '<<y<<std::endl;
		cin>>z;
		if(z==x||z==y)return cout<<"! "<<z,0;
		for(int v:g[x])if(--deg[v]==1)q.push(v);
		for(int v:g[y])if(--deg[v]==1)q.push(v);
	}
	cout<<"! "<<q.front();
	return 0;
}