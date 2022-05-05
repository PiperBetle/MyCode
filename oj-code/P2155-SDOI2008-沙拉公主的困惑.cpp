#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
bool pr[10000007];
int pt[10000007],pow_phi[10000007],len;
int inv[10000007],fac[10000007];
inline int qp(int n,int p,int k)
{
	int t=1;
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)
			t=t*n%k;
	return t;
}
inline int read()
{
	int x=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())
		x=(x<<1)+(x<<3)+(c^48);
	return x;
}
signed main()
{
	// freopen("divisor.in","r",stdin);
	// freopen("divisor.out","w",stdout);
	int i,j,k;
	int n,m,T=read();
	int ans=0,t,r=read(),sd;

	pow_phi[1]=inv[0]=fac[0]=inv[1]=fac[1]=1;
	for(i=2;i<=10000000;i++)
	{
		if(!pr[i])
			pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=10000000;j++)
		{
			pr[i*pt[j]]=1;
			if(i%pt[j]==0)break;
		}
	}
	for(i=2;i<=10000000;i++)
		if(pr[i])
		{
			sd=i;
			while(sd%r==0)
				sd/=r;
			pow_phi[i]=pow_phi[i-1]*sd%r;
		}
		else
		{
			sd=i-1;
			while(sd%r==0)
				sd/=r;
			pow_phi[i]=pow_phi[i-1]*sd%r;
		}
			
	for(i=2;i<=10000000;i++)
	{
		sd=i;
		while(sd%r==0)
			sd/=r;
		fac[i]=fac[i-1]*sd%r;
	}
	inv[10000000]=qp(fac[10000000],r-2,r);
	for(i=9999999;i>=1;i--)
	{
		sd=i+1;
		while(sd%r==0)
			sd/=r;
		inv[i]=inv[i+1]*sd%r;
	}

	for(k=1;k<=T;k++)
	{
		n=read();m=read();
		t=pow_phi[m];
		t=t*fac[n]%r*inv[m]%r;
		if(n>=r&&m<r)printf("0\n");
		else printf("%lld\n",t);
	}

	return 0;
}