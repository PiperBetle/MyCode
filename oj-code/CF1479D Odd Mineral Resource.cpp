#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<random>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
std::mt19937_64 rnd(std::random_device{}());
using uloli=decltype(rnd());
constexpr int kN=3e5+1;
int n,m,c[kN],fa[kN],sz[kN],gs[kN],dep[kN],top[kN];
std::basic_string<int>g[kN];
uloli rd[kN];
struct node{
	node *ls=nullptr,*rs=nullptr;
	uloli sum=0;
}*rt[kN];
#define mid ((l+r)/2)
void updata(node *&now,node *pre,int l,int r,int x,uloli k){
	if(!now)now=new node;
	if(!pre)pre=new node;
	now->sum=(pre->sum^k);
	if(l==r)return;
	if(x<=mid)now->rs=pre->rs,updata(now->ls,pre->ls,l,mid,x,k);
	else now->ls=pre->ls,updata(now->rs,pre->rs,mid+1,r,x,k);
}
int query(node *p1,node *p2,node *p3,node *p4,int l,int r,int x,int y){
	if(!p1)p1=new node;
	if(!p2)p2=new node;
	if(!p3)p3=new node;
	if(!p4)p4=new node;
	// assert(p1!=nullptr);
	// assert(p2!=nullptr);
	// assert(p3!=nullptr);
	// assert(p4!=nullptr);
	if(!(p1->sum^p2->sum^p3->sum^p4->sum))return -1;
	if(l==r)return l;
	if(x<=mid)if(int sum=query(p1->ls,p2->ls,p3->ls,p4->ls,l,mid,x,y);~sum)return sum;
	if(y>mid)if(int sum=query(p1->rs,p2->rs,p3->rs,p4->rs,mid+1,r,x,y);~sum)return sum;
	return -1;
}
#undef mid
void dfs1(int u){
	updata(rt[u],rt[fa[u]],1,n,c[u],rd[c[u]]);
	sz[u]=1;
	for(int v:g[u])if(v!=fa[u]){
		dep[v]=dep[u]+1;fa[v]=u;
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[gs[u]])gs[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	if(!gs[u])return;else dfs2(gs[u],t);
	for(int v:g[u])if(v!=fa[u]&&v!=gs[u])dfs2(v,v);
}
int LCA(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]])if(dep[top[u]]<dep[top[v]])std::swap(u,v);
	return dep[u]<dep[v]?u:v;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i],rd[i]=rnd();
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dep[1]=1;dfs1(1);dfs2(1,1);
	for(int u,v,lca,fal,l,r;m--;){
		cin>>u>>v>>l>>r;fal=fa[lca=LCA(u,v)];
		cout<<query(rt[u],rt[v],rt[lca],rt[fal],1,n,l,r)<<'\n';
	}
	return 0;
}