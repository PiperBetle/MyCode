#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<unordered_map>
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
constexpr int M=6;
int n,m,ans;
char a[M+1];
std::unordered_map<int,int>mp[1<<M];
inline int h(int x){
	int k=0;
	for(int j=0;j<m;j++){
		k*=27;
		if(a[j]!='?'&&x>>j&1)k+=a[j]-'a';
		else k+=26;
	}
	return k;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,k;i<=n;i++){
		cin>>a;k=0;
		for(int j=0;j<m;j++)k|=(a[j]!='?')<<j;
		for(int j=k;;(--j)&=k){
			if(mp[k].count(h(j)))
				ans+=mp[k][h(j)];
			if(!j)break;
		}
		for(int j=0;j<1<<m;j++)mp[j][h(j)]++;
	}
	cout<<ans<<'\n';
	return 0;
}