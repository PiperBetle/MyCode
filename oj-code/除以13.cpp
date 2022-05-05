#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char aa[101];
	int a[101],b=0,c[101],la,lc,i,j;
	
	gets(aa);
	for(i=1;i<=100;i++)a[i]=c[i]=0;
	la=strlen(aa);
	for(i=0;i<=la-1;i++)a[la-i]=aa[i]-'0';
	for(i=la;i>=1;i--)
	{
		b=b*10+a[i];
		c[i]=b/13;
		b=b%13;
	}
	for(i=la;;i--)
		if(c[i]!=0)
		{
			lc=i;
			break;
		}
	for(i=lc;i>=1;i--)cout<<c[i];
	cout<<endl<<b;
	
	return 0;
}
