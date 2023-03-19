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
int a[5000001];
int main()
{
	int i,n,k;
	int *p=a;
	
	p=a;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",p);
		p++;
	}
	sort(a,a+n);
	printf("%d",a[k]);
	
    return 0;
}
