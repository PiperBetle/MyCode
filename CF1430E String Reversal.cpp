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
constexpr int N=200001;
int n,a[N];
loli ans;
bsc s;
bsi p[26];
struct{
	int d[N];
	void add(int x){for(;x<=n;x+=x&-x)d[x]++;}
	void del(int x){for(;x<=n;x+=x&-x)d[x]--;}
	int ask(int x){int k=0;for(;x;x-=x&-x)k+=d[x];return k;}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>s;s=' '+s;
	for(int i=1;i<=n;i++)p[s[i]-'a']+=i;
	for(int i=0;i<26;i++)for(int j=0;j<siz(p[i]);j++)
		a[p[i][j]]=p[i][siz(p[i])-j-1];
	for(int i=1;i<=n;i++)a[i]=n-a[i]+1,ans+=tr.ask(a[i]),tr.add(1),tr.del(a[i]);
	cout<<ans;
	return 0;
}