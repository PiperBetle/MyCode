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
int a[101],b[101],la,lb=0;
char aa[101];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	scanf("%s",aa);
	la=strlen(aa);
	for(i=1;i<=la+1;i++)
	{
		a[i]=aa[la-i]-'0';
	}
//	puts(aa);
//	for(i=1;i<=la;i++)cout<<a[i];
	if(la%3==1)
	{
		a[la+1]=0;
		a[la+2]=0;
		la+=2;
	}
	if(la%3==2)
	{
		a[la+1]=0;
		la+=1;
	}
	for(i=3;i<=la;i+=3)
	{
		swap(a[i],a[i-2]);
		lb++;
		b[lb]=a[i-2]*4+a[i-1]*2+a[i];
	}
	for(i=lb;i>=1;i--)cout<<b[i];
	
	return 0;
}
