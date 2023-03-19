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
constexpr int N=1000001;
int n,a[N];
loli sum,ans=0x3f3f3f3f3f3f3f3f;
inline loli calc(loli x){
	loli cnt=0,res=0;
	for(int i=1;i<=n;i++)(cnt+=a[i])%=x,res+=std::min(cnt,x-cnt);
	return res;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(sum==1)return cout<<"-1",0;
	for(int i=2;1ll*i*i<=sum;i++)if(sum%i==0){
		while(sum%i==0)sum/=i;
		ans=std::min(ans,calc(i));
	}
	if(sum!=1)ans=std::min(ans,calc(sum));
	cout<<ans;
	return 0;
}