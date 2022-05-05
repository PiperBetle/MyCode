#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/priority_queue.hpp>
#define int long long
struct point{int id,dis;bool operator<(const point &n)const{return dis>n.dis;}};
__gnu_pbds::priority_queue<point>q;
using std::cin;using std::cout;
int f[1000007];
struct flyyy{int x,d,t,p;inline bool operator<(const flyyy &n)const{return x<n.x;}}a[1000007];
int set[1000007],len,dis[1000007];
bool vis[1000007];
struct edge{int go,data;};
std::vector<edge>s[1000007];
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i].x>>a[i].d>>a[i].t>>a[i].p,
		a[i].x-=a[i].p,a[i].d+=a[i].p,a[i].t+=a[i].p;
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++){
		if(a[i].x<0)continue;
		set[++len]=a[i].x;
		set[++len]=a[i].x+a[i].d;
	}
	set[++len]=0;
	set[++len]=m;
	std::sort(set+1,set+1+len);
	len=std::unique(set+1,set+1+len)-set-1;
	for(i=1;i<len;i++)
		s[i].emplace_back(edge{i+1,set[i+1]-set[i]}),
		s[i+1].emplace_back(edge{i,set[i+1]-set[i]});
	for(i=1;i<=n;i++){
		if(a[i].x<0)continue;
		int *begin=std::lower_bound(set+1,set+1+len,a[i].x);
		int *end=std::lower_bound(set+1,set+1+len,a[i].x+a[i].d);
		s[begin-set].emplace_back(edge{end-set,a[i].t});
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;q.push(point{1,0});
	while(!q.empty())
	{
		int now=q.top().id;q.pop();
		if(vis[now])continue;else vis[now]=1;
		for(auto it:s[now])if(dis[it.go]>dis[now]+it.data){
			dis[it.go]=dis[now]+it.data;
			if(!vis[it.go])q.push(point{it.go,dis[it.go]});
		}
	}
	cout<<dis[len];
	return 0;
}