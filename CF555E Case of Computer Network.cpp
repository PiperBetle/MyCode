#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
#define siz(x) int((x).size())
#define cauto const auto 
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=2e5+1;
std::basic_string<int>g1[N],g2[N];
int n1,n2,m,q,fn[N],low[N],bel[N],top[N],fa[N];
std::stack<int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n1>>m>>q;
	for(int i=1,u,v;i<=m;i++)cin>>u>>v,g1[u]+=v,g1[v]+=u;
	return 0;
}