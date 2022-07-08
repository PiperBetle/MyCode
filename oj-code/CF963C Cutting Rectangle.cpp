#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<unordered_map>
#include<cmath>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
using pll=std::pair<loli,loli>;
using vpll=std::vector<pll>;
vpll s;
int n,ans;
loli g;
std::unordered_map<loli,vpll>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(loli a,b,c;n--;)cin>>a>>b>>c,mp[a].emplace_back(b,c);
	for(auto&[v,t]:mp){
		std::sort(all(t));
		loli g=0;for(cauto&i:t)g=std::__gcd(g,i.second);
		for(auto&i:t)i.second/=g;
		::g=std::__gcd(::g,g);
		if(s.empty())s=t;else if(s!=t)return cout<<0,0;
	}
	for(loli i=1;i*i<=g;i++)if(g%i==0)ans+=2-(i*i==g);
	cout<<ans;
	return 0;
}