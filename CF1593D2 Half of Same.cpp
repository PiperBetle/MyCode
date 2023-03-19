#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<random>
#include<map>
#include<set>
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
constexpr int N=1e3+1,M=2e6+1;
int n,a[N];
std::mt19937 rng(std::random_device{}());
std::map<int,int>mp;
std::set<int>vis;
bool check(int x){
	if(vis.count(x))return false;else vis.insert(x);
	mp.clear();
	for(int i=1;i<=n;i++)if(++mp[(a[i]%x+x)%x]>=n/2)return true;
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<([]{
		cin>>n;vis.clear();	
		for(int i=1;i<=n;i++)cin>>a[i];
		std::sort(a+1,a+1+n);
		int cnt=1,ans=1;
		for(int i=2;i<=n;i++)if(a[i-1]==a[i]){if(++cnt>=n/2)return -1;}else cnt=1;
		for(int Y=100;Y;Y--){
			int k=abs(a[rng()%n+1]-a[rng()%n+1]);
			for(int i=1;i*i<=k;i++)if(k%i==0){
				if(check(i))cmax(ans,i);
				if(check(k/i))cmax(ans,k/i);
			}
		}
		return ans;
	}())<<'\n';
	return 0;
}