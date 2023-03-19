#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char aa[211],bb[211];
	int a[211],b[211],i,c[211],la,lb,lc,k,j,flag=1;
	
	for(i=1;i<=210;i++)a[i]=b[i]=c[i]=0;
	gets(aa);
	gets(bb);
	la=strlen(aa);
	lb=strlen(bb);
	if(aa[0]=='-')flag=-flag,aa[0]='0';
	if(bb[0]=='-')flag=-flag,bb[0]='0';
	for(i=0;i<=la-1;i++)a[la-i]=aa[i]-'0';
	for(i=0;i<=lb-1;i++)b[lb-i]=bb[i]-'0';
	
	for(i=la;i>=1;i--)
	{
		for(j=lb;j>=1;j--)
		{
			c[i+j-1]=c[i+j-1]+a[i]*b[j];
		}
	}
	
	k=0;
	for(j=1;j<=210;j++)
	{
		c[j]=c[j]+k;
		k=c[j]/10;
		c[j]=c[j]%10;
	}
	
	for(i=210;;i--)
		if(c[i]!=0)
		{
			lc=i;
			break;
		}
	if(lc==0)cout<<0;
	else
	if(flag==-1)cout<<'-';
	for(i=lc;i>=1;i--)cout<<c[i];
    
	return 0;
}
