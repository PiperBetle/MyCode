#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[1000001];
int main()
{
	int n,m,p;
	int i,t;
	int p1,p2,s1,s2;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	p1=1;p2=n;
	s1=s2=0;
	for(;;)
	{
		if(p1>p2)break;
		if(s1<=s2)
		{
			s1+=a[p1];
			p1++;
		}
		else
		{
			s2+=a[p2];
			p2--;
		}
	}
	printf("%d %d",p1-1,n-p2);
	
	return 0;
}
