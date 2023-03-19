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
constexpr int N=2e6+1;
int n,k;
struct{
	int d[N];
	void add(int x){for(;x<N;x+=x&-x)d[x]++;}
	void del(int x){for(;x<N;x+=x&-x)d[x]--;}
	int kth(int x){
		int p=1<<std::__lg(N);
		for(int i=std::__lg(N)-1;~i;i--)
			if(d[p-(1<<i)]>=x)p-=(1<<i);
			else x-=d[p-(1<<i)];
		return p;
	}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++)s.add(i);
	for(int i=1;--n;){
		i=(i+k-2)%(n+1)+1;
		int t=s.kth(i);
		cout<<t<<' ';
		s.del(t);
	}
	cout<<s.kth(1);
	return 0;
}