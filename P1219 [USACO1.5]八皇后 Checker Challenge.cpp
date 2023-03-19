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
using namespace std;
int n,m,a[101]={0},s[101]={0},ans=0;
bool b[101]={0},c[101]={0},d[101]={0};
void pr()
{
	int i,p=1;
	ans++;
	if(ans<=3)
	{
		for(i=1;i<=n;i++)printf("%d ",a[i]);
		puts("");
	}
}
void ss(int i)
{
	int j,k;
	for(j=1;j<=n;j++)
	{
		if((!b[j])&&(!c[i+j])&&(!d[i-j+20]))
		{
			a[i]=j;
			b[j]=1;
			c[i+j]=1;
			d[i-j+20]=11;
			if(i==n)pr();
			else ss(i+1);
			b[j]=0;
			c[i+j]=0;
			d[i-j+20]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	
	ss(1);
	printf("%d",ans);
	
	return 0;
}
