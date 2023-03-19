#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
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
constexpr int N=31;
int n,m,ans,a[N][N];
std::basic_string<int>s[N*2];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;ans=0;
		for(int i=2;i<=n+m;i++)s[i].clear();
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j],s[i+j]+=a[i][j];
		for(int l=2,r=n+m;l<=r;l++,r--){
			int cnt[2]={};
			for(int i:s[l])cnt[i]++;
			for(int i:s[r])cnt[i]++;
			if(l!=r)ans+=std::min(cnt[0],cnt[1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}