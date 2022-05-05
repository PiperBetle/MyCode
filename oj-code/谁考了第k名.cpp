#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int i,j,k,n,m,a[200];
	float b[200],c;
	
	cin>>n>>m; 
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(b[j]<b[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
	printf("%d %g",a[m],b[m]);
	
	return 0;
}
