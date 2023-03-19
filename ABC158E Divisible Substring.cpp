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
std::string s;
int n,p;
loli ans;
constexpr int kN=10001;
int cnt[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>p>>s;
	for(auto&c:s)c-='0';
	if(p==2||p==5){for(int i=0;i<siz(s);i++)if(s[i]%p==0)ans+=i+1;return cout<<ans,0;}
	std::reverse(s.begin(),s.end());
	cnt[0]=1;for(int sum=0,pw=1;int i:s)ans+=(cnt[(sum+=i*pw)%=p]++),(pw*=10)%=p;
	cout<<ans;
	return 0;
}