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
bsc s1,s2,s3;
int n;
char c1,c2,c3;
bsi p1,p2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>s1>>s2>>s3;c1=c2=c3='0';p1.clear();p2.clear();
		if(int(count(all(s1),'1'))*2>siz(s1))c1='1';
		if(int(count(all(s2),'1'))*2>siz(s2))c2='1';
		if(int(count(all(s3),'1'))*2>siz(s3))c3='1';
		if(c1==c3)swap(s2,s3),std::swap(c2,c3);
		else if(c2==c3)swap(s1,s3),std::swap(c1,c3);
		for(int i=0;i<siz(s1);i++)if(s1[i]==c1)p1+=i;
		for(int i=0;i<siz(s2);i++)if(s2[i]==c2)p2+=i;
		for(int i=0;i<n;cout<<c1,i++){
			for(int j=i?p1[i-1]+1:0;j<p1[i];j++)cout<<s1[j];
			for(int j=i?p2[i-1]+1:0;j<p2[i];j++)cout<<s2[j];
		}
		for(int i=p1[n-1]+1;i<siz(s1);i++)cout<<s1[i];
		for(int i=p2[n-1]+1;i<siz(s2);i++)cout<<s2[i];
		cout<<'\n';
	}
	return 0;
}