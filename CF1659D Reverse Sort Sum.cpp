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
constexpr int N=2e5+1;
int n,m,a[N],b[N];
struct{
	int d[N];
	void add(int x){for(;x<=n;x+=x&-x)d[x]++;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
	void clear(){memset(d+1,0,sizeof(int)*n);}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;m=0;tr.clear();
		for(int i=1;i<=n;i++)cin>>a[i],m+=a[i];
		m/=n;
		for(int i=n;i>=1;i--){
			if(a[i]-tr.ask(i)==i)b[i]=1;
			else b[i]=0;
			tr.add(i-m+1);
			m-=b[i];
		}
		for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}