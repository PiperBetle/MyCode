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
constexpr int N=101;
int n;
loli p[N],ans;
loli check(int x,loli k){
	loli sum=0,mul=x;
	while(mul<=k)sum+=k/mul,mul*=x;
	return sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=0;
		for(int i=1;i<=n;i++){
			int a;loli b;cin>>a>>b;
			for(int j=2;j*j<=a;j++)
				while(a%j==0)a/=j,p[j]+=b;
			if(a>1)p[a]+=b;
		}
		for(int i=2;i<N;i++)if(p[i]){
			loli l=0,r=1e16,mid;
			while(l<r)
				if(check(i,mid=(l+r)/2)>=p[i])r=mid;
				else l=mid+1;
			cmax(ans,l);p[i]=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}