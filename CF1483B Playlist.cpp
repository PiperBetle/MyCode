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
constexpr int N=100001;
int n,a[N],fa[N];
bool vis[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline int nxt(int i){return i%n+1;}
bsi ans;
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;memset(vis+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)cin>>a[i],fa[i]=i;
		for(int i=1;i<=n;i++)if(std::__gcd(a[i],a[nxt(i)])==1)q.push(i);
		while(!q.empty()){
			int x=q.front();q.pop();
			if(vis[x])continue;
			int y=nxt(find(x));
			fa[x]=find(y);
			ans+=y;
			vis[y]=true;
			if(siz(ans)==n)break;
			if(std::__gcd(a[x],a[nxt(fa[x])])==1)q.push(x);
		}
		while(!q.empty())q.pop();
		cout<<siz(ans)<<' ';
		for(int i:ans)cout<<i<<' ';
		cout<<'\n';
		ans.clear();
	}
	return 0;
}