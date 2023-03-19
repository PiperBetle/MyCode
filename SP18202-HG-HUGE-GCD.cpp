#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[100007],b[100007],c[100007],la,lb,lc,pa,pb;
int pt[40007],len;
bool pr[40007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;

	for(i=2;i<=40000;i++)
	{
		if(!pr[i])
			pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<=40000;j++)
		{
			pr[i*pt[j]]=1;
			if(!(i%pt[j]))break;
		}
	}
	scanf("%lld",&n);
	for(k=1;k<=n;k++)
	{
		scanf("%lld",&t);
		if(t<=1)continue;
		for(i=1;pt[i]*pt[i]<=t;i++)
			while(t%pt[i]==0)a[++la]=pt[i],t/=pt[i];
		if(t>1)a[++la]=t;
	}
	sort(a+1,a+1+la);

	scanf("%lld",&m);
	for(k=1;k<=m;k++)
	{
		scanf("%lld",&t);
		if(t<=1)continue;
		for(i=1;pt[i]*pt[i]<=t;i++)
			while(t%pt[i]==0)b[++lb]=pt[i],t/=pt[i];
		if(t>1)b[++lb]=t;
	}
	sort(b+1,b+1+lb);

	for(pa=pb=1;;)
	{
		if(pa>la||pb>lb)break;
		if(a[pa]<b[pb])pa++;
		else if(a[pa]>b[pb])pb++;
		else c[++lc]=a[pa],pa++,pb++;
	}
	int ans=1;bool flag=1;

	for(i=1;i<=lc;i++)
	{
		ans*=c[i];
		if(ans>1000000000)
			ans%=1000000000,flag=0;
	}
	if(flag)printf("%lld\n",ans);
	else printf("%09lld\n",ans);
	
	return 0;
}