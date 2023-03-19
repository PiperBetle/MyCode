#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
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
#include<ext/pb_ds/priority_queue.hpp>
template<typename T_>void operator+=(std::vector<T_>&x,T_ y){x.emplace_back(y);}
const int N=3e4+7;
int n,m,ans,a[N],d[12][N],g[N];
__gnu_pbds::priority_queue<pii,std::greater<>>q;
__gnu_pbds::priority_queue<pii,std::greater<>>::point_iterator p[N];
std::vector<pii>e[N];
std::vector<int>r[12];
inline void rkdj(int rk,int u=0){
	memset(d[rk]+1,0x3f,sizeof(d[rk][0])*n);
	memset(p+1,0,sizeof(p[0])*n);
	for(int i:r[rk])d[rk][i]=0,p[i]=q.push({0,i});
	while(!q.empty()){
		u=q.top().se,q.pop();
		for(auto[v,w]:e[u])if(d[rk][u]+w<d[rk][v]){
			d[rk][v]=d[rk][u]+w;
			if(p[v]!=nullptr)q.modify(p[v],{d[rk][v],v});
			else p[v]=q.push({d[rk][v],v});
		}
	}
}
inline void dj(int s){
	memset(p+1,0,sizeof(p[0])*n);
	memset(g+1,0x3f,sizeof(g[0])*n);
	g[s]=0,p[s]=q.push({0,s});
	while(!q.empty()){
		int u=q.top().se;q.pop();
		ans++;
		for(auto[v,w]:e[u])if(g[v]>g[u]+w){
			g[v]=g[u]+w;
			if(g[v]<d[a[s]+1][v]){
				if(p[v]!=nullptr)q.modify(p[v],{g[v],v});
				else p[v]=q.push({g[v],v});
			}
		}
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],r[a[i]]+=i;
	for(int i=1,x,y,z;i<=m;i++)cin>>x>>y>>z,e[x]+={y,z},e[y]+={x,z};
	for(int j=10;j;j--)rkdj(j);
	for(int j=9;j;j--)for(int i=1;i<=n;i++)
		if(d[j][i]>d[j+1][i])d[j][i]=d[j+1][i];
	for(int i=1;i<=n;i++)dj(i);
	cout<<ans<<'\n';
	return 0;
}