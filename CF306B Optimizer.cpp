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
constexpr int N=2e6+2;
int n,m,a[N],b[N],id[N];
bool vis[N];
std::basic_string<int>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,l,r;i<=m;i++)cin>>l>>r,r=l+r-1,a[l]++,a[r+1]--,r>b[l]&&(b[l]=r,id[l]=i);
	for(int i=1,l=0,r=0,p=0;i<=n;i++)b[i]>r&&(r=b[i],p=id[i]),(a[i]+=a[i-1])&&l<i&&(l=r,vis[p]=true);
	for(int i=1;i<=m;i++)if(!vis[i])ans+=i;
	cout<<siz(ans)<<'\n';for(int i:ans)cout<<i<<' ';
	return 0;
}