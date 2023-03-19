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
constexpr int kN=2e5+1;
int n,m,f[kN];
bool d[kN];
loli ans;
struct{int w,u,v;}a[kN];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i,d[i]=1;
	for(int i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].w;
	std::sort(a+1,a+1+m,[](cauto&x,cauto&y){return x.w>y.w;});
	for(int i=1;i<=m;i++){
		int x=find(a[i].u),y=find(a[i].v);
		if(x!=y&&(d[x]||d[y]))f[y]=x,ans+=a[i].w,d[x]&=d[y];
		else if(d[x])d[x]=0,ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}