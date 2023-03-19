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
constexpr int N=1e6+1,M=101;
int n,a[M],cnt[M],ans=1,sum;
bool pr[N];
bsi pt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	for(int j:pt){
		memset(cnt,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++)while(a[i]%j==0)a[i]/=j,cnt[i]++,cnt[0]++;
		if(!(cnt[0]/=n))continue;
		for(int i=1;i<=cnt[0];i++)ans*=j;
		for(int i=1;i<=n;i++)sum+=max(0,cnt[0]-cnt[i]);
	}
	cout<<ans<<' '<<sum;
	return 0;
}