#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
inline void exgcd(int a,int b,int &x,int &y)
{
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	int A,B,C,gcdab,P,Pp,x,y,z,X,Y;
	int ans;
	
	for(k=1;k<=T;k++)
	{
		// Ax+By+Cz=p
		// Ax+By=p-Cz
		ans=0;
		A=read();B=read();C=read();P=read();
		exgcd(A,B,x,y);
		gcdab=A*x+B*y;
		for(z=0;C*z<=P;z++)
		{
			Pp=P-C*z;
			if(Pp%gcdab)
				continue;
			X=x*Pp/gcdab;
			Y=y*Pp/gcdab;
			ans+=(floor(1.0*X*gcdab/B)-ceil(-1.0*Y*gcdab/A)+1);
		}
		printf("Case %lld: %lld\n",k,ans);
	}
	
	return 0;
}