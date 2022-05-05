#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using namespace std;
int f[500007];
inline int find(int x){return x==f[x]? x:f[x]=find(f[x]);}
inline int read()
{
    int w=0;char c;
    for(;!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())
        w=(w<<1)+(w<<3)+(c^48);
    return w;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
    int i,j,k;
	int n=read(),m=read(),q=read();
    int fx,fy;
	
    for(i=0;i<500007;i++)
        f[i]=i;
	while(m--)
    {
        fx=find(read());fy=find(read());
        if(fx!=fy)f[fx]=fy;
    }
    while(q--)
    {
        fx=find(read());fy=find(read());
        if(fx==fy)puts("Yes");
        else puts("No");
    }
	
	return 0;
}