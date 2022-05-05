#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[20000007],b[20000007],c[20000007],d[20000007];
int s1[20000007],s2[20000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,ans=0;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d%d",a+i,b+i,c+i,d+i);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)s1[++m]=a[i]+b[j],s2[m]=c[i]+d[j];
	std::sort(s1+1,s1+1+m);std::sort(s2+1,s2+1+m);
	for(i=1;i<=m;i++)
		ans+=std::upper_bound(s1+1,s1+1+m,-s2[i])-std::lower_bound(s1+1,s1+1+m,-s2[i]);
	printf("%d",ans);

	return 0;
}
