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
constexpr int N=18;
std::basic_string<int>b;
int n,m;
bool vis[1<<N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;vis[m]=true;
	for(int i=1;i<1<<n;i++)if(!vis[i])
		b+=i,vis[i]=vis[i^m]=true;
	for(int i=siz(b)-1;i>=1;i--)b[i]^=b[i-1];
	cout<<siz(b)<<'\n';
	for(int i:b)cout<<i<<' ';
	return 0;
}