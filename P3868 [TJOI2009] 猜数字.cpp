#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
constexpr venti operator""_vt(uloli x){return venti(x);}
inline void exgcd(int _a,int _b,int &_x,int &_y){if(_b)exgcd(_b,_a%_b,_y,_x),_y-=_a/_b*_x;else _x=1,_y=0;}
constexpr int N=11;
int n,m=1,ans,a[N],b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i],m*=b[i];
	for(int i=1;i<=n;i++)((a[i]%=b[i])+=b[i])%=b[i];
	for(int i=1,x,y,t;i<=n;i++){
		exgcd(t=m/b[i],b[i],x,y);
		((x%=b[i])+=b[i])%=b[i];
		ans=loli((ans+1_vt*t*x%m*a[i])%m);
	}
	cout<<(ans+m)%m;
	return 0;
}