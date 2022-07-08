#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int long long
#define MOD (m*m)
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
int n,m;
inline int qp(long long a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=a*t%MOD;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	cout<<(qp(10,n)/m)%m;
	return 0;
}