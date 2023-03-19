#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int la,lb=0,lc,n=0,i,j,ml,m,a[1001],b[1001];
	char c[1001];
	
	for(i=0;i<=1000;i++)a[i]=b[i]=c[i]=0;
	gets(c);
	lc=strlen(c);
	for(i=0;;i++)
	{
		if(c[i]==' ')
		{
			la=i;
			break;
		}
		a[i]=c[i]-'0';
	}
	for(i=la+1;i<lc;i++)
	{
		b[i-la-1]=c[i]-'0';
		lb++;
	}
	
	for(i=0;i<la;i++)
	{
		for(j=0;j<lb;j++)
		{
			n+=a[i]*b[j];
		}
	}
	cout<<n;
	
	return 0;
}
