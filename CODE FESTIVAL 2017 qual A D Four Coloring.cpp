#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
auto s="RYGB";
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,d;cin>>n>>m>>d;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)
		cout<<s[(i+j)/d%2*2+(i+m-j)/d%2]<<(j==m-1?"\n":"");
	return 0;
}