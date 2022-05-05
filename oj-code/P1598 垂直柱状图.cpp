#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
char a[1001];
int sum[31]={0};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int t,maxn=-1,n,x,y,la;
	string flag;
	
	for(k=1;k<=4;k++)
	{
		gets(a);
		la=strlen(a);
		for(i=0;i<la;i++)
		{
			if(('A'<=a[i])&&(a[i]<='Z'))
				sum[a[i]-'A'+1]++;
		}
	}
	maxn=-1;
	for(i=1;i<=26;i++)maxn=max(maxn,sum[i]);
	for(i=maxn;i>=1;i--)
	{
		for(j=26;j>=0;j--)
		{
			if(sum[j]>=i)
			{
				k=j;
				break;
			}
		}
		for(j=1;j<=k;j++)
		{
			if(j!=1)putchar(' ');
			if(sum[j]>=i)
			{
				putchar('*');
			}
			else
			{
				putchar(' ');
			}
		}
		puts("");
	}
	putchar('A');
	for(i=1;i<=25;i++)
	{
		putchar(' ');
		putchar(i+'A');
	}
	
	return 0;
}
