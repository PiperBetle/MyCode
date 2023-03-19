#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool pr[1300007];
int pt[1300007],len=0;
inline int read()
{
	int f=1,w=0;char c;
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar()) w=(w<<1)+(w<<3)+(c^48);
	return w*f;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n=read(),m,T;
	int *p;
	
	for(i=0;i<1300000;i++)
		pr[i]=1;
	pr[1]=0;
	for(i=2;i<1300000;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>=1300000)
				break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
				break;
		} 
	}
	for(;;n=read())
	{
		if(n==0)
			return 0;
		p=lower_bound(pt+1,pt+1+100000,n);
		if(*p==n)
			printf("0\n");
		else
			printf("%lld\n",*p-*(p-1));
	}
	
    return 0;
}