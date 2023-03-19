#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
namespace GenHelper{unsigned z1,z2,z3,z4,b;unsigned rand_(){b=((z1<<6)^z1)>>13;z1=((z1&4294967294U)<<18)^b;b=((z2<<2)^z2)>>27;z2=((z2&4294967288U)<<2)^b;b=((z3<<13)^z3)>>21;z3=((z3&4294967280U)<<7)^b;b=((z4<<3)^z4)>>12;z4=((z4&4294967168U)<<13)^b;return (z1^z2^z3^z4);}}
void srand(unsigned x){using namespace GenHelper;z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
int read(){using namespace GenHelper;int a=rand_()&32767;int b=rand_()&32767;return a*32768+b;}
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
constexpr int N=20000001,M=5001,blk=10000;
int n,m,s,a[N],l[N],r[N],q[N],num,mx[M][M];
uloli sum;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>s;
	srand(s);num=(n-1)/blk+1;
	for(int i=1;i<=n;i++){
		l[i]=r[i]=a[i]=read();
		q[i]=(i-1)/blk+1;
		cmax(mx[q[i]][q[i]],a[i]);
	}
	for(int i=1;i<=n;i++)cmax(l[i],q[i]==q[i-1]?l[i-1]:0);
	for(int i=n;i>=1;i--)cmax(r[i],q[i]==q[i+1]?r[i+1]:0);
	for(int i=1;i<=num;i++)for(int j=i+1;j<=num;j++)
		mx[i][j]=std::max(mx[i][j-1],mx[j][j]);
	for(int x,y;m--;){
		x=read()%n+1;y=read()%n+1;
		if(x>y)std::swap(x,y);
		if(q[x]==q[y])sum+=*std::max_element(a+x,a+1+y);
		else sum+=std::max({mx[q[x]+1][q[y]-1],r[x],l[y]});
	}
	cout<<sum;
	return 0;
}