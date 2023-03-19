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
constexpr int N=1e7+10;
bool has7(int x){for(;x;x/=10)if(x%10==7)return 0;return 1;}
int vis[N],lis[N],cnt;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=1;i<N;i++)if(!vis[i]){
		if(has7(i))lis[vis[i]=++cnt]=i;
		else for(int j=i;j<N;j+=i)vis[j]=-1;
	}
	int T;cin>>T;for(int x;T--;)cin>>x,cout<<(~vis[x]?lis[vis[x]+1]:-1)<<'\n';
	return 0;
}