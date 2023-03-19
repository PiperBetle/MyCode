#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int i,j,k,n,m,b[200];
	string a[200],c;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(i=1;i<=n-1;i++)
		for(j=1;j<=n-i;j++)
			if(b[j]<b[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
			else 
			if((b[j]==b[j+1])&&(a[j]>a[j+1]))
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
	for(i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<endl;
	
	return 0;
}
