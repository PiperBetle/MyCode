#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<queue>
#include<vector>
using std::cin;using std::cout;
using pii=std::pair<int,int>;
struct red_flag{int a,b,c,d;}a[1000007];
int b[2000007],lb,n,m,dis[1000007],pre[1000007];
std::unordered_map<int,int>map;
bool vis[1000007];
std::queue<int>q;
std::set<pii>tree[1000007];
inline int lowbit(int x){return x&-x;}
inline void add(int x,pii k){for(;x<=m;x+=lowbit(x))tree[x].insert(k);}
auto query(int x,int y){
	std::vector<int>sum;
	for(;x;x-=lowbit(x)){
		auto p=tree[x].upper_bound({y,0x3f3f3f3f});
		for(auto it=tree[x].begin();it!=p;it++)sum.emplace_back(it->second);
		tree[x].erase(tree[x].begin(),p);
	}
	return sum;
}
void find(int x){if(pre[x])find(pre[x]);cout<<x<<' ';}
signed main(){
//	freopen("healthy.in","r",stdin);
//	freopen("healthy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d,
		b[++lb]=a[i].a,b[++lb]=a[i].c;
	std::sort(b+1,b+lb+1);
	map[b[1]]=++m;
	for(int i=2;i<=lb;i++)if(b[i]>b[i-1])map[b[i]]=++m;
	for(int i=1;i<=n;i++)add(map[a[i].a],{a[i].b,i}),dis[i]=0x3f3f3f3f;
	while(!q.empty())q.pop();
	auto v=query(map[0],0);
	for(auto it:v)q.emplace(it),vis[it]=true,dis[it]=1;
	while(!q.empty()){
		int now=q.front();q.pop();
		auto v=query(map[a[now].c],a[now].d);
		for(auto it:v){
			if(vis[it])continue;
			vis[it]=true;dis[it]=dis[now]+1;
			pre[it]=now;q.emplace(it);
		}
	}
	if(dis[n]==0x3f3f3f3f)return cout<<"-1",0;
	cout<<dis[n]<<'\n';find(n);
	return 0;
}