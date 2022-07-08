#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
constexpr int inf=10000;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,y=0,cnt=0;cin>>n>>m;
	if(n>4&&m==3)return cout<<"-1",0;
	for(int i=0;i<m;i++)cout<<i<<' '<<(y+=cnt++)<<'\n';
	if(m<n)cout<<m+inf<<' '<<y<<'\n';
	for(int i=m+1;i<n;i++)cout<<i+inf<<' '<<(y-=--cnt)<<'\n';
	return 0;
}