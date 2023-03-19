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
constexpr int N=3e5+1,inf=0x3f3f3f3f;
int n1,n2,n3,m1=inf,m2=inf,m3=inf,a[N],b[N],c[N];
loli s1,s2,s3,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>n2>>n3;
	for(int i=1;i<=n1;i++)cin>>a[i],s1+=a[i],cmin(m1,a[i]);
	for(int i=1;i<=n2;i++)cin>>b[i],s2+=b[i],cmin(m2,b[i]);
	for(int i=1;i<=n3;i++)cin>>c[i],s3+=c[i],cmin(m3,c[i]);
	for(int i=1;i<=n1;i++)cmax(ans,s2+s3-m2-m3-a[i]+max(llabs(s1-a[i]-m2)+m3,llabs(s1-a[i]-m3)+m2));
	for(int i=1;i<=n2;i++)cmax(ans,s1+s3-m1-m3-b[i]+max(llabs(s2-b[i]-m1)+m3,llabs(s2-b[i]-m3)+m1));
	for(int i=1;i<=n3;i++)cmax(ans,s1+s2-m1-m2-c[i]+max(llabs(s3-c[i]-m1)+m2,llabs(s3-c[i]-m2)+m1));
	cout<<ans;
	return 0;
}