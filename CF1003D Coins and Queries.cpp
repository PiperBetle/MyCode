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
int n,q,cnt[40];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	for(int i=1,x;i<=n;i++)cin>>x,cnt[std::__lg(x)]++;
	for(int b,ans;q--;){
		cin>>b;ans=0;
		for(int i=30;~i;i--){
			int k=std::min(cnt[i],b/(1<<i));
			ans+=k;
			b-=k*(1<<i);
		}
		cout<<(b?-1:ans)<<'\n';
	}
	return 0;
}