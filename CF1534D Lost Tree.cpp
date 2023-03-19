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
int n;
bsi b1,b2;
std::vector<pii>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;(cout<<"? 1\n").flush();
	for(int i=1,x;i<=n;i++){
		if(cin>>x,x)(x&1?b1:b2)+=i;
		if(x==1)ans.emplace_back(1,i);
	}
	if(siz(b1)>siz(b2))std::swap(b1,b2);
	for(int u:b1){
		(cout<<"? "<<u<<'\n').flush();
		for(int v=1,x;v<=n;v++)
			if(cin>>x,x==1&&v!=1)ans.emplace_back(u,v);
	}
	cout<<"! \n";
	for(auto[x,y]:ans)cout<<x<<' '<<y<<'\n';
	return 0;
}