#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-');
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
int a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m=read(),ans=0;
	
	for(i=1;i<=n;i++)a[i]=read();
	while(m--)ans+=min(a[read()],a[read()]);
	printf("%lld",ans);
	
	return 0;
}
