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
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+2;
int n,L,R,a[N],pre[N],suf[N],ans=0x3f3f3f3f3f3f3f3f;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>L>>R;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre[i]=std::min(pre[i-1]+a[i],L*i);
	for(int i=n;i>=1;i--)suf[i]=std::min(suf[i+1]+a[i],R*(n-i+1));
	for(int i=0;i<=n;i++)ans=std::min(ans,pre[i]+suf[i+1]);
	cout<<ans;
	return 0;
}