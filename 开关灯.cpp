#include<iostream>
using namespace std;
int main()
{
	int i,n,m,j;
	
	cin>>n>>m;
	int a[n+1];
	for(i=1;i<=n;i++)
		a[i]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			if(i%j==0)a[i]=1-a[i];
		}
	if((n>=1)&&(m>=1))cout<<1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==1)cout<<","<<i;
	}
	
	return 0;
}
