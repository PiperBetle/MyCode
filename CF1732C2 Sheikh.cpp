//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
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
constexpr int N=1.1e5+1;
int n,m,q,a[N],b[N],sm[N],xr[N];
int calc(int l,int r){return (sm[r]-sm[l-1])-(xr[r]^xr[l-1]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>q;m=0;
		for(int i=1;i<=n;i++)if(cin>>a[i],a[i])b[++m]=i,a[m]=a[i];
		n=m;for(int i=1;i<=n;i++)sm[i]=sm[i-1]+a[i],xr[i]=xr[i-1]^a[i];
		for(int l,r,k;q--;){
			cin>>l>>r;k=l;
			l=int(std::lower_bound(b+1,b+1+n,l)-b);
			r=int(std::upper_bound(b+1,b+1+n,r)-b)-1;
			int ml=0,mr=0x3f3f3f3f,op=calc(l,r);
			if(!op){cout<<k<<' '<<k<<'\n';continue;}
			for(int i=l;i<=min(l+32,r);i++)for(int j=max(i,r-32);j<=r;j++)
				if(calc(i,j)>=op&&b[j]-b[i]<mr-ml)ml=b[i],mr=b[j];
			cout<<ml<<' '<<mr<<'\n';
		}
	}
	return 0;
}