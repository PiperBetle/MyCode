#pragma GCC optimize(2)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
int dis[200007],begin,end;
bool bj[200007];
std::vector<int>s[200007];
struct point{int p,step;bool operator<(const point&n)const{return step>n.step;}}go;
std::priority_queue<point>q;
inline bool check(int x)
{
	while(!q.empty())q.pop();
	memset(dis,0x3f,sizeof dis);
	q.push((point){begin,0});dis[begin]=0;
	while(!q.empty())
	{
		point now=q.top();q.pop();
		if(now.step==x)continue;
		for(auto it:s[now.p])
		{
			go.p=it;go.step=now.step+1;
			if(go.p==end)return 1;
			if(bj[go.p])go.step=0;
			if(dis[go.p]>go.step)dis[go.p]=go.step,q.push(go);
		}
	}
	return 0;
}
signed main()
{
//	freopen("energy.in","r",stdin);
//	freopen("energy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int u,v,t;
	
	cin>>n>>m>>k;
	for(i=1;i<=k;i++)cin>>t,bj[t]=1;
	for(i=1;i<=m;i++){cin>>u>>v;s[u].emplace_back(v);s[v].emplace_back(u);}
	cin>>begin>>end;
	int left=1,right=n,ans=-1;
	while(left<=right)
	{
		int mid=left+right>>1;
		if(check(mid))ans=mid,right=mid-1;
		else left=mid+1;
	}
	cout<<ans;
	
	return 0;
}