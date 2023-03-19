#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<unordered_set>
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
int n,m,A[N],B[N],a[N],b[N],la,lb;
std::unordered_set<int>mp;
int solve(){
	std::sort(a+1,a+1+la);std::sort(b+1,b+1+lb);
	mp.clear();int res=0;
	for(int i=1;i<=la;i++)mp.insert(a[i]);
	for(int i=1;i<=lb;i++)res+=mp.count(b[i]);
	int ans=res;
	for(int i=1;i<=lb;i++){
		if(mp.count(b[i])){res--;continue;}
		int p1=int(std::lower_bound(a+1,a+1+la,b[i])-a)-1;
		int p2=int(std::upper_bound(b+1,b+1+lb,b[i]-p1)-b);
		cmax(ans,res+i-p2+1);
	}
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>A[i];
		for(int i=1;i<=m;i++)cin>>B[i];
		la=lb=0;
		for(int i=1;i<=n;i++)if(A[i]>=0)a[++la]=A[i];
		for(int i=1;i<=m;i++)if(B[i]>=0)b[++lb]=B[i];
		int ans=solve();
		la=lb=0;
		for(int i=1;i<=n;i++)if(A[i]<0)a[++la]=-A[i];
		for(int i=1;i<=m;i++)if(B[i]<0)b[++lb]=-B[i];
		cout<<ans+solve()<<'\n';
	}
	return 0;
}