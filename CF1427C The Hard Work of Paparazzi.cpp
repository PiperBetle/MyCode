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
constexpr int N=501,M=100001;
int n,m,k=0xbfbfbfbf,f[M],x[M],y[M],t[M];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;x[0]=y[0]=1;
	for(int i=1;i<=m;i++)cin>>t[i]>>x[i]>>y[i];
	memset(f+1,0xbf,sizeof(int)*m);
	for(int i=1;i<=m;i++){
		for(int j=std::max(0,i-2*n+1);j<i;j++)if(t[i]-t[j]>=abs(x[i]-x[j])+abs(y[i]-y[j]))f[i]=std::max(f[i],f[j]+1);
		f[i]=std::max(f[i],k+1);if(i>=n*2)k=std::max(k,f[i-n*2]);
	}
	cout<<*std::max_element(f,f+1+m);
	return 0;
}