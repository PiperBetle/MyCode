#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=18,inf=0x3f3f3f3f;
int g[kN],f[1<<kN],n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)g[i]|=(1<<i);
	for(int i=0,u,v;i<m;i++)cin>>u>>v,u--,v--,g[u]|=(1<<v),g[v]|=(1<<u);
	for(int k=1;k<(1<<n);k++){
		f[k]=1;
		for(int i=0;i<n;i++)if((k>>i&1)&&((g[i]&k)!=k)){f[k]=inf;break;}
		for(int i=k;i;i=(i-1)&k)f[k]=std::min(f[k],f[i]+f[k-i]);
	}
	cout<<f[(1<<n)-1];
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}