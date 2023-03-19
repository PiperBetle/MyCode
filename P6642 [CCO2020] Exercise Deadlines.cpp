#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
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
constexpr int N=2e5+1,inf=0x3f3f3f3f;
int a[N],n,b[N];
loli ans;
std::set<int>s={-inf,inf};
struct BIT{
	int data[N];
	void add(int x,int k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=data[x];return k;}
}bt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s.insert(i);
	for(int i=n;i>=1;i--){
		auto it=s.upper_bound(a[i]);
		if(*it>a[i]){if(it==++s.begin())return cout<<"-1",0;else --it;}
		b[i]=*it;
		s.erase(it);
	}
	for(int i=n;i>=1;i--){
		ans+=bt.query(b[i]);
		bt.add(b[i]);
	}
	cout<<ans;
	return 0;
}