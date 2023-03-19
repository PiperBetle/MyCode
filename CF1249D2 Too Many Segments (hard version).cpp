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
bsi ans;
std::priority_queue<pii>q;
struct BIT{
	int d[N]={};
	void updata(int x,int k){for(;x<N;x+=x&-x)d[x]+=k;}
	void add(int l,int r,int k=+1){updata(l,k);updata(r+1,-k);}
	void sub(int l,int r,int k=-1){updata(l,k);updata(r+1,-k);}
	int operator[](int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
}tr;
pii a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,tr.add(a[i].fi,a[i].se),b[i]=i;
	std::sort(b+1,b+1+n,[](int x,int y){return a[x]<a[y];});
	for(int i=1,j=1;i<N;i++){
		while(j<=n&&a[b[j]].fi<=i)q.emplace(a[b[j]].se,b[j]),j++;
		while(tr[i]>m)tr.sub(i,q.top().fi),ans+=q.top().se,q.pop();
	}
	cout<<siz(ans)<<'\n';
	std::sort(all(ans));
	for(int i:ans)cout<<i<<' ';
	return 0;
}