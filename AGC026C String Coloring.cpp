#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
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
std::map<std::pair<std::string,std::string>,int>mp;
int n;
loli ans;
std::string a;
void dfs1(int u,std::string s1,std::string s2){
	if(u==n+1){mp[{s1,s2}]++;return;}
	dfs1(u+1,s1+a[u],s2);
	dfs1(u+1,s1,s2+a[u]);
}
void dfs2(int u,std::string s1,std::string s2){
	if(u==n){if(mp.count({s1,s2}))ans+=mp[{s1,s2}];return;}
	dfs2(u-1,s1+a[u],s2);
	dfs2(u-1,s1,s2+a[u]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>a;a=' '+a;
	dfs1(1,"","");dfs2(n*2,"","");
	cout<<ans;
	return 0;
}