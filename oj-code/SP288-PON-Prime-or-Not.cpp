#include<iostream>
#include<cstdio>
#include<cstring>
#define int __int128
using namespace std;
int pr[]={0,2,3,5,7,11,13,17,37};
inline int read()
{
	int x=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		x=(x<<1)+(x<<3)+(c^48);
	return x;
}
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
inline int qm(int x,int y,int p)
{
	int t=0;
	if(y==0)return 0;
	for(;y;y>>=1,x=(x<<1)%p)
		if(y&1)
			t=(t+x)%p;
	return t;
}
bool miller_rabin(int n)
{
	if(n==1)
		return 0;
	int a,b,i,j,k;
	int x=0,y=n-1;
	while(!(y&1))
		x++,y>>=1;
	for(i=1;i<=8&&pr[i]<n;i++)
	{
		a=pr[i];
		b=qp(a,y,n);
		for(j=1;j<=x;j++)
		{
			k=qm(b,b,n);
			if(k==1&&b!=1&&b!=n-1)
				return 0;
			b=k;
		}
		if(b!=1)
			return 0;
	}
	return 1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	
	T=read();
	while(T--)
	{
		n=read();
		if(miller_rabin(n))puts("YES");
		else puts("NO");
	}
		
	return 0;
}