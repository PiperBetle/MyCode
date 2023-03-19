#include<iostream>
using namespace std;
long long a[50001];
int main()
{
	int x,y,i,j,k,a[1001],b[1001],la,lb;
	
	cin>>x>>y;
	la=0;
	lb=0;
	for(i=1;i<=x;i++)
	{
		if(x%i==0)
		{
			la++;
			a[la]=i;
		}
	}
	for(i=1;i<=y;i++)
	{
		if(y%i==0)
		{
			lb++;
			b[lb]=i;
		}
	}
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
		{
			cout<<a[i]<<" "<<b[j]<<endl;
		}
	}
	
	return 0;
}
