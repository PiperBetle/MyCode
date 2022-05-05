#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
//#define max(a,b) (((a)>(b))?(a):(b))
//#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int p[1000007];//问题数组 
int f[1000007];//装下i 
int i,j,k;
int ans=0,maxn=-1,q,u;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
inline int max(int a,int b) { return a>b?a:b; }
inline int min(int a,int b) { return a<b?a:b; }
signed main()
{
	freopen("squnum.in","r",stdin);
	freopen("squnum.out","w",stdout);
//	std::ios::sync_with_stdio(false);
	
	k=read(),q=read();
	for(i=1;i<=q;i++)
	{
		p[i]=read();
		maxn=max(maxn,p[i]);
	}
	for(i=0;i<=maxn;i++)
		f[i]=i;
	
	for(i=int(sqrt(maxn));i;i--)
	{
		u=i*i;
		if(i!=k)
			for(j=u;j<=maxn;j++)
			{
				f[j]=min(f[j],f[j-u]+1);
			}
	}
//	cout<<endl<<k<<endl;
//	for (i=1;i<=maxn;i++)
//		for (j=int(sqrt(i));j>max(int(sqrt(i))-120,0);j--)
//			if (j!=k) 
//				(cout<<i<<" "<s<j<<endl),
//				f[i]=min(f[i],f[i-j*j]+1);
//	for (i=1;i<=50;i++) cout<<" "<<f[i];
	for(i=1;i<=q;i++)
		printf("%d\n",f[p[i]]);
//		cout<<f[p[i]]<<endl;
//	system("pause");
    return 0;
}

