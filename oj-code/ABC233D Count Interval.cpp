#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
std::unordered_map<loli,int>mp;
loli a[kN],ans,m;
int n;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	mp[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]+=a[i-1],ans+=mp[a[i]-m],mp[a[i]]++;
	cout<<ans;
	return 0;
}