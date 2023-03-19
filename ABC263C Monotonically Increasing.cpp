#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
int n,m;
std::basic_string<int>ans;
void dfs(int u,int d){
	if(u==n+1){
		for(int i:ans)cout<<i<<' ';
		cout<<'\n';
		return;
	}
	for(int i=d;i<=m;i++){
		ans+=i;
		dfs(u+1,i+1);
		ans.pop_back();
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	dfs(1,1);
	return 0;
}