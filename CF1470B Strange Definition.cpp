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
constexpr int N=1e6+1;
bsi pt;
bool pr[N];
int n,m1,m2;
std::unordered_map<int,int>mp;
void solve(int x){
	for(int i:pt){
		int j=i*i;
		while(x%j==0)x/=j;
		if(x<j)break;
	}
	mp[x]++;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	int T;cin>>T;while(T--){
		cin>>n;mp.clear();m1=m2=0;
		for(int i=1,x;i<=n;i++)cin>>x,solve(x);
		for(auto[x,y]:mp)if(cmax(m1,y),x==1||y%2==0)m2+=y;
		cmax(m2,m1);cin>>n;
		for(loli x;n--;)cin>>x,cout<<(x?m2:m1)<<'\n';
	}
	return 0;
}