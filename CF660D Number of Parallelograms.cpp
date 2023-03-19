#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
std::map<pii,int>mp;
constexpr int kN=2e3+1;
int n;
pii a[kN];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)mp[{a[i].first+a[j].first,a[i].second+a[j].second}]++;
	for(cauto &it:mp)ans+=1ll*it.second*(it.second-1)/2;
	cout<<ans;
	return 0;
}