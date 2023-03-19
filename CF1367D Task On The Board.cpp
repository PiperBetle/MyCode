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
constexpr int N=51;
bsc s;
char t[N];
bsi p;
int m,cnt[26],b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		memset(cnt,0,sizeof cnt);
		cin>>s>>m;s=' '+s;
		for(int i=1;i<siz(s);i++)cnt[s[i]-'a']++;
		for(int i=1;i<=m;i++)cin>>b[i];
		for(char c='z';c>='a';c--){
			p.clear();
			for(int i=1,k;i<=m;i++)if(!t[i]){
				k=0;
				for(int j=1;j<=m;j++)if(t[j])k+=abs(i-j);
				if(k==b[i])p+=i;
			}
			while(cnt[c-'a']<siz(p))c--;
			for(int i:p)t[i]=c;
		}
		for(int i=1;i<=m;i++)cout<<t[i],t[i]=0;
		cout<<'\n';
	}
	return 0;
}