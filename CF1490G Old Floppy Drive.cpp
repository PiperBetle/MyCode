#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
#define int loli
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
int n,m,a[N],s[N],sm;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;sm=0;
		for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
		sm=s[n];for(int i=2;i<=n;i++)cmax(s[i],s[i-1]);
		for(int x;m--;){
			cin>>x;
			if(x<=s[n]){cout<<std::lower_bound(s+1,s+1+n,x)-s-1<<' ';continue;}
			if(sm<=0){cout<<"-1 ";continue;}
			int cnt=x/sm*n-1;
			int res=(s[n]-(x%=sm))/sm;
			cnt-=res*n;x+=res*sm;
			cout<<std::lower_bound(s+1,s+1+n,x)-s+cnt<<' ';
		}
		cout<<'\n';
	}
	return 0;
}