#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
struct edge{int u,v,t1,t2,id;}a[20007];
std::vector<edge>b;
int f[10007];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,k,n,m,cnt=0,ans=0;
	cin>>n>>k>>m;
	for(i=1;i<=n;i++)f[i]=i;
	for(i=1;i<m;i++)cin>>a[i].u>>a[i].v>>a[i].t1>>a[i].t2,a[i].id=i;
	std::sort(a+1,a+m,[&](const edge&x,const edge&y){return x.t1<y.t1;});
	for(i=1;i<m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy)continue;
		f[fx]=fy;ans=std::max(ans,a[i].t1);
		b.emplace_back(a[i]);
		if(++cnt==k)break;
	}
	std::sort(a+1,a+m,[&](const edge&x,const edge&y){return x.t2<y.t2;});
	for(i=1;i<m;i++){
		int fx=find(a[i].u),fy=find(a[i].v);
		if(fx==fy)continue;
		f[fx]=fy;ans=std::max(ans,a[i].t2);
		b.emplace_back(a[i]);
		a[i].id=-a[i].id;
		if(++cnt==n-1)break;
	}
	cout<<ans<<'\n';
	for(auto it:b)cout<<it.u<<' '<<it.v<<'\n';
	return 0;
}