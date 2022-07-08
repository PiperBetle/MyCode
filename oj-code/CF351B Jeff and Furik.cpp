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
constexpr int kN=3001;
int n,a[kN],ans;
struct BIT{
	int data[kN];
	void updata(int x,int k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=data[x];return k;}
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)ans+=s.query(a[i]-1),s.updata(a[i]);
	cout<<ans*2-ans%2<<".000000";
	return 0;
}