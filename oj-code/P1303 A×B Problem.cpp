#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char aa[5001]={0},bb[5001]={0};
	int a[5001]={0},b[5001]={0},c[10001]={0},la,lb,lc,i,j,k,t,jw;
	
	scanf("%s%s",aa,bb);
	la=strlen(aa);
	lb=strlen(bb);
	lc=max(la,lb);
	for(i=1;i<=la;i++)
	{
		a[i]=aa[la-i]-'0';
	}
	for(i=1;i<=lb;i++)
	{
		b[i]=bb[lb-i]-'0';
	}
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
		{
			c[i+j-1]=c[i+j-1]+a[i]*b[j];
		}
	}
	for(i=1;i<=la+lb-1;i++)
	{
		c[i+1]=c[i+1]+c[i]/10;
		c[i]%=10;
	}
	lc=la+lb;
	while((c[lc]==0)&&(lc>1))lc--;
	for(i=lc;i>=1;i--)cout<<c[i];

	return 0;
}
