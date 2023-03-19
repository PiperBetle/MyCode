#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int __int128
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int f[2007][2007];
inline int read()
{
	int w=0,c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
inline void write(int x)
{
	if(x>9)write(x/10);
	putchar(x%10+48);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int r,g,b;
	int ans=0;
	
	n=read();r=read();g=read();b=read();t=read();
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)
	{
		if(i>0)f[i][j]=max(f[i][j],f[i-1][j]+j*g*(t+(i-1)*b));
		if(j>0)f[i][j]=max(f[i][j],f[i][j-1]+(j-1)*g*(t+i*b));
	}
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)
        ans=max(ans,f[i][j]+(t+i*b)*(r+g*j)*(n-i-j));
    write(ans);
	
	return 0;
}