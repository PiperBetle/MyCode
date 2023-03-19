虽然是朴素的筛法，但是跑的比希儿的 Pollard-rho 快。  
$\mathcal O(n\sqrt n)$ 的质因数分解是不行的，Pollard-rho 的码量也过于麻烦，直接在线性筛里筛出每个数的最小质因子，怎么筛？线性筛的本质是每个数只会被自己的最小质因子筛到，记录即可。  
对分母分子每个数筛出来的质因子放入桶里，对两个桶取 `min` 就是要除掉的部分。  
再对分母分子进行筛，如果筛出来的质因子在桶里有，把桶里的计数减去 `1`，否则就不去除这个数。  
代码（略有压行）：
```cpp
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
constexpr int N=1e7+1;
int n,m,mif[N];
std::basic_string<int>pt,ans1,ans2;
bool pr[N];
pii cnt[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){if(!pr[i])pt+=i,mif[i]=i;for(int j:pt){if(i*j>=N)break;pr[i*j]=true;mif[i*j]=j;if(i%j==0)break;}}
	cin>>n>>m;
	for(int i=1,x;i<=n;i++)for(int p=mif[cin>>x,ans1+=x,x];x!=1;p=mif[x/=p])cnt[p].fi++;
	for(int i=1,x;i<=m;i++)for(int p=mif[cin>>x,ans2+=x,x];x!=1;p=mif[x/=p])cnt[p].se++;
	for(int i=1,x;i<N;i++)if(cnt[i].fi<cnt[i].se)cnt[i].se=cnt[i].fi;else cnt[i].fi=cnt[i].se;
	cout<<n<<' '<<m<<'\n';
	for(int y;int x:ans1){for(int p=mif[y=1,x];x!=1;p=mif[x/=p])if(cnt[p].fi>0)cnt[p].fi--;else y*=p;cout<<y<<' ';}
	cout<<'\n';
	for(int y;int x:ans2){for(int p=mif[y=1,x];x!=1;p=mif[x/=p])if(cnt[p].se>0)cnt[p].se--;else y*=p;cout<<y<<' ';}
	return 0;
}
```