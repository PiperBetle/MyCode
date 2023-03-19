#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	char aa[5001],bb[5001];
	int a[5001],b[5001],la,lb,lc,c[5001],i,flag=1,qw;
	
	scanf("%d",&qw);
	for(i=0;i<=5000;i++)a[i]=b[i]=c[i]=0;
	scanf("%s%s",aa,bb);
	la=strlen(aa);
	lb=strlen(bb);
	lc=max(la,lb);
	for(i=1;i<=lc;i++)
	{
		if(('0'<=aa[la-i])&&(aa[la-i]<='9'))a[i]=aa[la-i]-'0';
		else a[i]=aa[la-i]-'A'+10;
		if(('0'<=bb[lb-i])&&(bb[lb-i]<='9'))b[i]=bb[lb-i]-'0';
		else b[i]=bb[lb-i]-'A'+10;
	}
	for(i=1;i<=lc;i++)
	{
		if(a[i]<0)a[i]=0;
		if(b[i]<0)b[i]=0;
	}
	for(i=1;i<=lc+10;i++)
	{
		c[i]=a[i]+b[i];
		if(c[i]>=qw)
		{
			c[i]%=qw;
			a[i+1]++;
		}
	}
 	for(i=lc+1;i>=1;i--)
		if(c[i]!=0)
		{
			lc=i;
			break;
		}
//	puts(aa);
//	puts(bb);
//	for(i=1;i<=la;i++)cout<<a[i];
//	cout<<endl;
//	for(i=1;i<=lb;i++)cout<<b[i];
//	cout<<endl;
	for(i=lc;i>=1;i--)
	{
//		flag=0;
		if(c[i]>=10)cout<<(char)(c[i]-10+'A');
		else cout<<c[i];
	}
//	if(flag)cout<<0;
	
	return 0;
}
