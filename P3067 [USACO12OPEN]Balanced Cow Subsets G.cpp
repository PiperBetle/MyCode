#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#include<bitset>
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
constexpr int N=20,M=10;
using btst=std::bitset<1<<M>;
struct easy_hash{size_t operator()(int x)const{return ((1919810ull*x)^19260817)+114514;}};
std::unordered_map<int,btst,easy_hash>mp;
btst vis[1<<M];
int n,m,a[N],ans;
void dfs1(int u,int sum,int id){
	if(u==m){mp[sum].set(id);return;}
	dfs1(u+1,sum,id);
	dfs1(u+1,sum+a[u],id|(1<<u));
	dfs1(u+1,sum-a[u],id|(1<<u));
}
void dfs2(int u,int sum,int id){
	if(u==n){
		if(!mp.count(sum))return;
		auto s=mp[sum];
		ans+=int((s&=~vis[id]).count());
		vis[id]|=s;
		return;
	}
	dfs2(u+1,sum,id);
	dfs2(u+1,sum+a[u],id|(1<<u-m));
	dfs2(u+1,sum-a[u],id|(1<<u-m));
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=n/2;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs1(0,0,0);
	dfs2(m,0,0);
	cout<<ans-1;
	return 0;
}