#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ranges>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=3e4+1,kM=300;
int n,m,cnt[kN],f[kN][kM*2+10];
bool check(int x,int k){
	int dt=m+k-kM;
	return 0<dt&&x+dt<kN;
}
int dfs(int x,int k){
	int &now=f[x][k];
	if(now!=-1)return now;else now=0;
	if(check(x,k))now=std::max(now,dfs(x+k+m-kM,k));
	if(check(x,k-1))now=std::max(now,dfs(x+k+m-kM-1,k-1));
	if(check(x,k+1))now=std::max(now,dfs(x+k+m-kM+1,k+1));
	return now+=cnt[x];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)cin>>x,cnt[x]++;
	memset(f,-1,sizeof f);
	cout<<dfs(m,kM);
	return 0;
}