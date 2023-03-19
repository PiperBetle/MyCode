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
constexpr int N=40;
int n,mid;
loli m,a[N],ans;
std::basic_string<loli>b1,b2;
void dfs1(int u,loli sum){
	if(sum>m)return;
	if(u==mid){b1+=sum;return;}
	dfs1(u+1,sum);
	dfs1(u+1,sum+a[u]);
}
void dfs2(int u,loli sum){
	if(sum>m)return;
	if(u==n){b2+=sum;return;}
	dfs2(u+1,sum);
	dfs2(u+1,sum+a[u]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;mid=n/2;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs1(0,0);dfs2(mid,0);
	std::sort(all(b1));
	for(loli i:b2)ans+=loli(std::upper_bound(all(b1),m-i)-b1.begin());
	cout<<ans;
	return 0;
}