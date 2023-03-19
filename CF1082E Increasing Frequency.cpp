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
constexpr int N=5e5+1;
int n,c,cnt[N],lst[N],sum,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>c;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(x==c){sum++;continue;}
		cnt[x]=std::max(cnt[x]+lst[x]-sum+1,1);
		lst[x]=sum;
		ans=std::max(ans,cnt[x]);
	}
	cout<<ans+sum;
	return 0;
}