#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<tuple>
#include<string>
using std::cin;using std::cout;
std::vector<int>s[3007];
std::map<std::tuple<int,int,int>,bool>mp;
std::map<std::pair<int,int>,bool>vis;
struct point{int id,dis,pre;};
template<typename any>struct queue{
	std::vector<any>data;int begin;
	queue(){begin=0,data.clear();}
	inline void push(any x){data.emplace_back(x);}
	inline bool empty(){return begin>=(int)data.size();}
	inline void pop(){begin++;}
	inline any front(){return data[begin];}
	inline int size(){return data.size()-begin;}
};
queue<point>q;
std::string print(point now){if(now.pre==-1)return "\n1 ";return print(q.data[now.pre])+std::to_string(now.id)+' ';}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,k,n,m,u,v,t;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)cin>>u>>v,s[u].emplace_back(v),s[v].emplace_back(u);
	for(i=1;i<=k;i++)cin>>u>>v>>t,mp[{u,v,t}]=true;
	for(q.push(point{1,0,-1});!q.empty();q.pop()){
		point now=q.front();
		for(auto it:s[now.id]){
			if(mp[{q.data[now.pre].id,now.id,it}])continue;
			if(vis[{now.id,it}])continue;else vis[{now.id,it}]=true;
			if(it==n)return cout<<now.dis+1<<print(now)<<n,0;
			q.push(point{it,now.dis+1,q.begin});
		}
	}
	return cout<<"-1",0;
}