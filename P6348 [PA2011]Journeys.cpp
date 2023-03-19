#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<deque>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).end(),(x).begin()
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
constexpr int N=5000001;
std::vector<pii>g[N];
int n,m,s,id[N],dis[N];
std::deque<int>q;
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
void build1(int u,int l,int r){
	if(l==r)return;
	build1(ls,l,mid);g[u].emplace_back(ls,0);
	build1(rs,mid+1,r);g[u].emplace_back(rs,0);
}
void build2(int u,int l,int r){
	g[u].emplace_back(u+n*4,0);
	if(l==r){id[l]=u+n*4;return;}
	build2(ls,l,mid);g[ls+n*4].emplace_back(u+n*4,0);
	build2(rs,mid+1,r);g[rs+n*4].emplace_back(u+n*4,0);
}
void merge1(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		g[k].emplace_back(u,1);
		g[u+n*4].emplace_back(k+1,1);
		return;
	}
	if(x<=mid)merge1(ls,l,mid,x,y,k);
	if(y>mid)merge1(rs,mid+1,r,x,y,k);
}
void merge2(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){
		g[k+1].emplace_back(u,1);
		g[u+n*4].emplace_back(k,1);
		return;
	}
	if(x<=mid)merge2(ls,l,mid,x,y,k);
	if(y>mid)merge2(rs,mid+1,r,x,y,k);
}
#undef ls
#undef rs
#undef mid
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>s;
	build1(1,1,n);build2(1,1,n);
	for(int i=1,a,b,c,d;i<=m;i++){
		cin>>a>>b>>c>>d;
		merge1(1,1,n,a,b,n*8+i*2);
		merge2(1,1,n,c,d,n*8+i*2);
	}
	memset(dis,0x3f,sizeof dis);
	dis[id[s]]=0;q.push_front(id[s]);
	while(!q.empty()){
		int u=q.front();q.pop_front();
		for(auto[v,w]:g[u])if(dis[v]>dis[u]+w){
			dis[v]=dis[u]+w;
			w?q.push_back(v):q.push_front(v);
		}
	}
	for(int i=1;i<=n;i++)cout<<dis[id[i]]/2<<'\n';
	return 0;
}