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
constexpr int N=501;
int n,m,a[N],b[N],ans;
bool g[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cout<<"? ";g[i]=true;
		for(int j=1;j<=m;j++)cout<<g[j];
		g[i]=false;endl(cout);
		cin>>a[i];b[i]=i;
	}
	std::sort(b+1,b+1+m,[](int x,int y){return a[x]<a[y];});
	for(int i=1,x;i<=m;i++){
		cout<<"? ";g[b[i]]=true;
		for(int j=1;j<=m;j++)cout<<g[j];
		endl(cout);cin>>x;
		if(x-ans==a[b[i]])ans=x;
		else g[b[i]]=false;
	}
	cout<<"! "<<ans;
	return 0;
}