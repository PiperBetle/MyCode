#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=100001;
int n,n1,n2,m,p[kN];
pii a[kN];
int tr[kN];
inline void updata(int x,int k){for(;x<=n;x+=x&-x)tr[x]+=k;}
inline int query(int x){int k=0;for(;x;x-=x&-x)k+=tr[x];return k;}
signed main(){
//	freopen("sun.in","r",stdin);
//	freopen("sun.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>n2;n=n1+n2;
	for(int i=n1;i>=1;i--)cin>>a[i].first,a[i].second=i;
	for(int i=1;i<=n2;i++)cin>>a[i+n1].first,a[i+n1].second=i+n1;
	std::sort(a+1,a+1+n,std::greater<pii>());
	for(int i=1;i<=n;i++)p[i]=a[i].second;
	m=n1;loli ans=0;
	for(int i=1;i<=n;i++){
		int pre=m,now=p[i]-(p[i]>m);
		ans+=abs(pre-now)-(query(std::max(pre,now))-query(std::min(pre,now)));
		updata(p[i],1);m=now;
	}
	cout<<ans;
	return 0;
}