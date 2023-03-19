#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/priority_queue.hpp>
namespace pbds=__gnu_pbds;
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e6+1;
int n,m,fa[kN];
bool vis[kN];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
pbds::priority_queue<pii,std::greater<>>q[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,w;i<=n;i++)cin>>w,fa[i]=i,q[i].push({w,i});
	cin>>m;
	for(char c;m--;){
		int x,y;
		cin>>c>>x;
		if(c=='M'){
			cin>>y;
			if(vis[x]||vis[y]||(x=find(x))==(y=find(y)))continue;
			fa[y]=x;q[x].join(q[y]);
		}else{
			if(vis[x]){cout<<"0\n";continue;}
			auto[w,id]=q[x=find(x)].top();q[x].pop();
			vis[id]=true;cout<<w<<'\n';
		}
	}
	return 0;
}