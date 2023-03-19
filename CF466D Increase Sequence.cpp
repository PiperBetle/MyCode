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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+2,MOD=1e9+7;
int n,m,a[N],cnt,ans=1;
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)cin>>x,a[i]=m-x;
	for(int i=1;i<=n+1;i++)switch(a[i]-a[i-1]){
	case -1:mul1(ans,cnt--);break;
	case 0:mul1(ans,cnt+1);break;
	case 1:cnt++;break;
	default:return cout<<0,0;
	}
	cout<<ans;
	return 0;
}