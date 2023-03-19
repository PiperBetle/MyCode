#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
#define siz(x) int((x).wize())
#define cauto const auto
#define aloli(x) (x).begin(),(x).end()
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
constexpr int N=1200111;
struct edge{int u,v,w;}e[N];
int n,m,k,fa[N];
bool cmp(edge x,edge y){return x.w<y.w;}
int find(int x){if(fa[x]==x)return x;return fa[x]=find(fa[x]);}
loli solve(int x,int y){
	for(int i=1;i<=n+2;++i)fa[i]=i;
	loli sum=0;int cnt=0;
	for(int i=1;i<=k;++i){
		if(e[i].v==n+1&&!x)continue;
		if(e[i].v==n+2&&!y)continue;
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx!=fy)fa[fx]=fy,sum+=e[i].w,cnt++;
	}
	if(cnt<n+x+y-1)return 0x3f3f3f3f3f3f3f3f;
	return sum;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>e[++k].w,e[k].u=i,e[k].v=n+1;
	for(int i=1;i<=n;++i)cin>>e[++k].w,e[k].u=i,e[k].v=n+2;
	for(int i=1;i<=m;++i)k++,cin>>e[k].u>>e[k].v>>e[k].w;
	std::sort(e+1,e+1+k,cmp);
	loli ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)
		ans=std::min(ans,solve(i,j));
	cout<<ans;
}