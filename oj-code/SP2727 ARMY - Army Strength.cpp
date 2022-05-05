#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
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
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T=read();
	int maxn,maxm;
	
	while(T--)
	{
		n=read();m=read();
		maxn=maxm=0;
		while(n--)maxn=max(maxn,read());
		while(m--)maxm=max(maxm,read());
		if(maxn>=maxm)puts("Godzilla");
		else puts("MechaGodzilla");
	}
	
	return 0;
}
