#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<unordered_set>
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
int n,m,a[N];
loli cnt;
std::unordered_set<int>vis;
std::queue<pii>q;
bsi ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],vis.insert(a[i]);
	for(int i=1;i<=n;i++){
		if(!vis.count(a[i]-1))q.emplace(a[i]-1,1),vis.insert(a[i]-1);
		if(!vis.count(a[i]+1))q.emplace(a[i]+1,1),vis.insert(a[i]+1);
	}
	while(siz(ans)<m){
		auto[x,d]=q.front();q.pop();
		ans+=x;cnt+=d;
		if(!vis.count(x-1))q.emplace(x-1,d+1),vis.insert(x-1);
		if(!vis.count(x+1))q.emplace(x+1,d+1),vis.insert(x+1);
	}
	cout<<cnt<<'\n';
	for(int i:ans)cout<<i<<' ';
	return 0;
}