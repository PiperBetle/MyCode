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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=500001;
int n,m,a[N];
bool vis[N];
std::basic_string<int>b;
loli ans;
signed main(){
//	freopen("flag.in","r",stdin);
//	freopen("flag.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)if(!vis[a[i]]&&m)vis[a[i]]=true,b+=i,m--;
	if(m)return cout<<"-1",0;
	for(int i=0;i<siz(b);i++)ans+=abs(b[i]-i-1);
	cout<<ans;
	return 0;
}