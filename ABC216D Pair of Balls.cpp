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
constexpr int N=2e5+1;
int n,m,b[N];
std::queue<int>q[N];
void dfs(int u){
	int v=b[q[u].front()];
	q[u].pop();q[v].pop();
	while(!q[v].empty()&&b[q[v].front()])dfs(v);
	if(!q[v].empty())b[q[v].front()]=v;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,l,x;i<=m;i++)for(cin>>l;l--;)cin>>x,q[i].push(x);
	for(int i=1;i<=m;i++){
		while(!q[i].empty()&&b[q[i].front()])dfs(i);
		if(!q[i].empty())b[q[i].front()]=i;
	}
	for(int i=1;i<=m;i++)if(!q[i].empty())return cout<<"No",0;
	cout<<"Yes";
	return 0;
}