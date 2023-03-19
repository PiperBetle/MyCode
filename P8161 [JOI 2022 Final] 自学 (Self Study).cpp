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
constexpr int N=3e5+1,inf=0x3f3f3f3f3f3f3f3f;
int n,m,ans,a[N],b[N];
inline bool check(int x){
	venti d1=0,d2=0;//多出来 额外补
	for(int i=1;i<=n;i++)
		if(m*a[i]>=x){
			if(x%a[i]==0)d1+=m-x/a[i];
			else d1+=m-x/a[i]-1;
		}else{
			int y=x-m*a[i];
			if(y%b[i]==0)d2+=y/b[i];
			else d2+=y/b[i]+1;
		}
	return d1>=d2;
}
signed main(){
	freopen("tx.in","r",stdin);
	freopen("tx.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(cin>>b[i],a[i]<b[i])a[i]=b[i];
	for(int l=1,r=inf,mid;l<=r;){
		if(check(mid=(l+r)/2))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}