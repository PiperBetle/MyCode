#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_set>
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
auto rev(uloli x) {
	static std::basic_string<int>b;
	b.clear();
	do b+=x%2,x/=2;while(x);
	uloli y=0;
	for(int i:b)y=y*2+i;
	return y;
}
std::unordered_set<uloli>s;
uloli x,y;
void dfs(uloli u){
	if(u>2*y)return;
	if(u==y)cout<<"YES",exit(0);
	if(s.count(u))return;
	s.insert(u);
	dfs(rev(u));
	dfs(rev(u*2+1));
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>x>>y;
	dfs(x);dfs(rev(x));
	cout<<"NO";
	return 0;
}