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
	cin>>n>>m;ans1.reserve(n),ans2.reserve(m);
	for(int i=1,x;i<=n;i++)for(int p=mif[cin>>x,ans1+=x,x];x!=1;p=mif[x/=p])cnt[p].fi++;
	for(int i=1,x;i<=m;i++)for(int p=mif[cin>>x,ans2+=x,x];x!=1;p=mif[x/=p])cnt[p].se++;
	for(int i=1,x;i<N;i++)if(cnt[i].fi<cnt[i].se)cnt[i].se=cnt[i].fi;else cnt[i].fi=cnt[i].se;
	cout<<n<<' '<<m<<'\n';
	for(int y;int x:ans1){for(int p=mif[y=1,x];x!=1;p=mif[x/=p])if(cnt[p].fi>0)cnt[p].fi--;else y*=p;cout<<y<<' ';}
	cout<<'\n';
	for(int y;int x:ans2){for(int p=mif[y=1,x];x!=1;p=mif[x/=p])if(cnt[p].se>0)cnt[p].se--;else y*=p;cout<<y<<' ';}
	return 0;
}