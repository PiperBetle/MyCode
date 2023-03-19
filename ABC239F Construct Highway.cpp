#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
constexpr int kN=2e5+1;
using pii=std::pair<int,int>;
std::vector<pii>ans;
std::basic_string<int>g[kN],p[kN],p1;
std::vector<std::basic_string<int>>p2;
int n,m,sum,deg[kN],fat[kN];
inline int find(int x){return fat[x]==x?x:fat[x]=find(fat[x]);}
inline bool merge(int x,int y){return ((x=find(x))==(y=find(y)))?0:(fat[x]=y,1);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>deg[i],sum+=deg[i],fat[i]=i;
	if(sum!=2*n-2)return cout<<"-1",0;
	for(int x,y;m--;){
		cin>>x>>y;
		if(!merge(x,y))return cout<<"-1",0;
		deg[x]--,deg[y]--;
	}
	for(int i=1;i<=n;i++)
		if(deg[i]<0)return cout<<"-1",0;
		else p[find(i)].append(deg[i],i);
	for(int i=1;i<=n;i++){
		if(p[i].empty())continue;
		if(siz(p[i])==1)p1+=p[i][0];
		else p2.emplace_back(p[i]);
	}
	for(const auto &v:p2){
		for(int i=0;i<siz(v)-1;i++){
			if(p1.empty())return cout<<"-1",0;
			ans.emplace_back(v[i],p1.back());
			merge(v[i],p1.back());
			p1.pop_back();
		}
		p1+=v.back();
	}
	if(siz(p1)!=2)return cout<<"-1",0;
	ans.emplace_back(p1[0],p1[1]);
	merge(p1[0],p1[1]);
	for(int i=1;i<n;i++)if(find(i)!=find(i+1))return cout<<"-1",0;
	for(auto[u,v]:ans)cout<<u<<' '<<v<<'\n';
	return 0;
}