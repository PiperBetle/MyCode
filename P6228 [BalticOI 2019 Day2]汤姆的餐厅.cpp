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
constexpr int N=301,M=N*N;
int n,m,k,b[N],f[M],sum1,sum2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;memset(f,-0x3f,sizeof f);f[0]=0;
	for(int i=1,x;i<=n;i++)if(cin>>x,x<k)return cout<<"Impossible",0;else sum1+=x;
	for(int i=1,x;i<=m;i++)for(int j=(cin>>x,sum2+=x);j>=x;j--)f[j]=std::max(f[j],f[j-x]+std::min(x,n));
	for(int i=sum1;i<=sum2;i++)if(f[i]>=n*k)return cout<<i-sum1,0;
	cout<<"Impossible";
	return 0;
}