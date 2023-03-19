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
constexpr int N=501;
int n,m,w,h,k,a[N][N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>w>>h;k=std::max(n,m);
	if(n%w==0&&m%h==0)return cout<<"No",0;else cout<<"Yes\n";
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		cout<<(i%w==0&&j%h==0?-k*(h*w)+k-1:k)<<" \n"[j==m];
	return 0;
}