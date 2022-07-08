#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=101,kV=121,kC=10001,kZ=kC+kV*kV,inf=0x3f3f3f3f;
int n,m1,m2,f[kZ],g[kZ],v[kN],c[kN];
auto sqr(auto x){return x*x;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m1;
	for(int i=1;i<=n;i++)cin>>v[i];
	int sum=0;
	for(int i=1;i<=n;i++)cin>>c[i],sum+=c[i]*v[i];
	m2=m1+sqr(*std::max_element(v+1,v+1+n));
	memset(f+1,0x3f,sizeof(int)*m2);
	memset(g+1,0x3f,sizeof(int)*m1);
	f[0]=g[0]=0;
	for(int i=1;i<=n;i++)for(int j=v[i];j<=m1;j++)g[j]=std::min(g[j],g[j-v[i]]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i];c[i]-=j,j*=2)for(int k=m2;k>=j*v[i];k--)f[k]=std::min(f[k],f[k-j*v[i]]+j);
		if(c[i])for(int k=m2;k>=c[i]*v[i];k--)f[k]=std::min(f[k],f[k-c[i]*v[i]]+c[i]);
	}
	int ans=inf;
	for(int i=m1;i<=m2;i++)ans=std::min(ans,f[i]+g[i-m1]);
	cout<<(ans==inf?-1:ans);
	return 0;
}