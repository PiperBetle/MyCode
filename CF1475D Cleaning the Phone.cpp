#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<numeric>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
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
bsi b1,b2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<[]{
		b1.clear();b2.clear();
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1,x;i<=n;i++)cin>>x,(x==1?b1:b2)+=a[i];
		if(std::accumulate(all(b1),0ll)+std::accumulate(all(b2),0ll)<m)return -1;
		std::sort(all(b1),std::greater<>());b1.resize(n,0);
		std::sort(all(b2),std::greater<>());b2.resize(n,0);
		int p1=0,p2=0,ans=0;
		while(m>0){
			if(m<=b1[p1])ans++,m-=b1[p1++];
			else if(b2[p2]>=b1[p1]+b1[p1+1])ans+=2,m-=b2[p2++];
			else ans++,m-=b1[p1++];
		}
		return ans;
	}()<<'\n';
	return 0;
}