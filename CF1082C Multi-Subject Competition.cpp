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
constexpr int N=1e5+1;
int n,m,sum[N];
std::basic_string<int>a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v;i<=n;i++)cin>>u>>v,a[u]+=v;
	for(int i=1;i<=m;i++){
		std::sort(all(a[i]),std::greater<>());
		for(int j=0,k=0;j<siz(a[i]);j++){
			if((k+=a[i][j])<0)break;
			sum[j]+=k;
		}
	}
	cout<<*std::max_element(sum,sum+n);
	return 0;
}