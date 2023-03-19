#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,inf=0x3f3f3f3f;
int n,a[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<n;i++)if((a[1]<a[i]&&a[i]>a[i+1])||(a[1]>a[i]&&a[i]<a[i+1]))
		return cout<<"3\n1 "<<i<<' '<<i+1,0;
	return cout<<0,0;
}