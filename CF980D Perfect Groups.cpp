#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define int loli
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=5001;
int a[kN],f[kN],n,ans[kN];
bool b[kN];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))f[x]=y;}
inline bool issqr(int x){int y=int(sqrtl(1.l*x));return y*y==x;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],f[i]=i;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i]*a[j]>0&&issqr(a[i]*a[j]))merge(i,j);
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(b+1,0,sizeof(bool)*n);
		for(int j=i;j<=n;j++)
			if(a[j]){if(!b[find(j)])b[find(j)]=1,cnt++;ans[cnt]++;}
			else ans[std::max(1ll,cnt)]++;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}