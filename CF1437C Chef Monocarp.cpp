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
constexpr int N=401,inf=0x3f3f3f3f;
int n,a[N],f[N][N],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;ans=inf;
		for(int i=1;i<=n;i++)cin>>a[i];
		std::sort(a+1,a+1+n);
		for(int j=1;j<N;j++)f[1][j]=abs(a[1]-j);
		for(int i=2;i<=n;i++){
			memset(f[i]+1,0x3f,sizeof(int)*(N-1));
			for(int j=i;j<N;j++)for(int k=i-1;k<j;k++)
				cmin(f[i][j],f[i-1][k]+abs(j-a[i]));
		}
		cout<<*std::min_element(f[n]+n,f[n]+N)<<'\n';
	}
	return 0;
}