#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,m,a[kN];
loli ans=0;
inline int&add1(int&x,int y){return (x+=y)<m?x:x-=m;}
inline int&sub1(int&x,int y){return (x-=y)<0?x+=m:x;}
std::unordered_map<int,int>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],add1(a[i]%=m,a[i-1]);
	for(int i=1;i<=n;i++)sub1(a[i],i%m);
	for(int i=0;i<=n;i++){
		if(i>=m)mp[a[i-m]]--;
		ans+=mp[a[i]]++;
	}
	cout<<ans;
	return 0;
}