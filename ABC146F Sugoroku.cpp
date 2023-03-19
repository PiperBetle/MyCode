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
constexpr int kN=1e5+1,inf=0x3f3f3f3f;
int n,m,f[kN];
std::string s;
std::basic_string<int>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;s.reserve(n+1);cin>>s;
	for(int i=n;i;){
		for(int j=std::min(m,i);j;j--)if(s[i-j]=='0'){
			i-=j;ans+=j;goto next;
		}
		return cout<<"-1",0;
		next:;
	}
	for(int i=siz(ans)-1;~i;i--)cout<<ans[i]<<' ';
	return 0;
}