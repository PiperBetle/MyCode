#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
constexpr int N=31;
int n,m,r,a[N],b[N],k[N],p[N],ans=loli(0x8000000000000000);
void dfs(int u,int d[],bool t){
	if(u==m+1){
		int sum=0;
		for(int i=1;i<=n;i++)sum+=d[i]*k[i];
		ans=std::max(ans,sum);
		return;
	}
	if((m-u)&1)dfs(m+1,d,true);
	int c[N];
	if(t){for(int i=1;i<=n;i++)c[i]=d[i]^b[i];dfs(u+1,c,false);}
	for(int i=1;i<=n;i++)c[i]=d[p[i]]+r;dfs(u+1,c,true);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)cin>>p[i];
	dfs(1,a,true);cout<<ans;
	return 0;
}