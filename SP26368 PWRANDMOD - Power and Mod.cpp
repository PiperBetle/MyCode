#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int __uint128_t
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline int qp(int k,int p,int a,int t=1){for(;p;p>>=1,a=a*a%k)if(p&1)t=t*a%k;return t;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	
	while(T--)write(qp(read(),read(),read())),putchar('\n');

	return 0;
}
