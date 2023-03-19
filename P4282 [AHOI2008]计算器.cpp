#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int n,m,i,j,k,a[100001],t=0;
	
	cin>>n;
	cin>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if((a[j]-a[i])>m)
				break;
			t++;
		}
	}
	cout<<t;
	
	return 0;
}
