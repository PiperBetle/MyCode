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
constexpr int N=1001;
int n,m,ans,p,a[N][N];
bool vis[N][N];
bool check(int x){
	for(int i=1;i<=m;i++)memset(vis[i]+1,0,sizeof(bool)*m);
	static std::basic_string<int>s;
	for(int i=1;i<=n;i++){
		s.clear();
		for(int j=1;j<=m;j++)if(x<=a[i][j]){
			for(int k:s)if(vis[k][j])return true;else vis[k][j]=true;
			s+=j;
		}
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],p=std::max(p,a[i][j]);
	for(int i=std::__lg(p);~i;i--)if(check(ans+(1<<i)))ans+=(1<<i);
	cout<<ans;
	return 0;
}