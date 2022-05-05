#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	char aa[5000007],bb[5000007];
	int a[5000007],b[5000007],la,lb,lc,c[5000007],i,flag=1;
	
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(c,0,sizeof c);
	scanf("%s%s",aa,bb);
	la=strlen(aa);
	lb=strlen(bb);
	lc=max(la,lb);
	for(i=1;i<=lc;i++)
	{
		a[i]=aa[la-i]-'0';
		b[i]=bb[lb-i]-'0';
	}
	for(i=1;i<=lc;i++)
	{
		if(a[i]<0)a[i]=0;
		if(b[i]<0)b[i]=0;
	}
	for(i=1;i<=lc+1;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]>=10)
		{
			c[i]%=10;
			a[i+1]++;
		}
	}
 	for(i=lc+1;i>=1;i--)
		if(c[i]!=0)
		{
			lc=i;
			break;
		}
	for(i=lc;i>=1;i--)
		cout<<c[i];
	
	return 0;
}
