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
int n,k,ans,cnt[26];
bsc s;
bool check(int v,int x){
	for(int i=0;i<26;i++)
		if((v-=cnt[i]/x)<=0)return true;
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>k>>s;s=' '+s;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
		ans=*std::max_element(cnt,cnt+26);
		for(int v=2;v<=k;v++)if(k%v==0){
			int l=1,r=n/v,mid;
			while(l<=r)
				if(check(v,mid=(l+r)/2))cmax(ans,v*mid),l=mid+1;
				else r=mid-1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}