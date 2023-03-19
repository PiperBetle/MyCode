#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<numeric>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=1e5+1;
int f[kN],n,m,d[kN];
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;std::iota(f+1,f+1+n,1);
	for(int x,y;m--;){
		cin>>x>>y;
		if(++d[x]>2||++d[y]>2)return cout<<"No",0;
		if((x=find(x))==(y=find(y)))return cout<<"No",0;else f[x]=y;
	}
	cout<<"Yes";
	return 0;
}