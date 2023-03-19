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
int a[101]={0},b[101]={0},n,r;
void pr()
{
	int i;
	for(i=1;i<=r;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}
void s(int now)
{
	if(now>r)
	{
		pr();
		return;
	}
	int i;
	for(i=a[now-1]+1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			a[now]=i;
			s(now+1);
			b[i]=0;
		}
	}
	return;
}
int main()
{
	cin>>n>>r;
	s(1);
	
	return 0;
}
