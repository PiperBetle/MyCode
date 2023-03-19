#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
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
constexpr int N=1e4+1,M=51;
std::bitset<N>a[M];
int n,k;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1,m,t;i<=n;i++){
		for(cin>>m;m--;)cin>>t,a[i].set(t);
		for(int j=1;j<i;j++)if((a[i]&a[j]).none())
			return cout<<"impossible",0;
	}
	cout<<"possible";
	return 0;
}