#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(u) int((u).size())
#define cauto const auto
#define all(u) (u).begin(),(u).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli u){return venti(u);}
const int N=1e4+1;
int n,m,f[N],sum,a[N];
int dfs(int u){
	if(!u)return u;
	if(f[u])return f[u];
	for(int i=1;i<=m;i++)
		if(a[i]<=u)f[u]=std::max(f[u],u-dfs(u-a[i])); 
	return f[u];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	cout<<dfs(n);
	return 0;
}