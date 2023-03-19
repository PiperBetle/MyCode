#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,k,ans=-1;

	cin>>i>>j;
	for(;i<=j;i++)
	{
		n=i;
		m=1;
		while(n!=1)
		{
			if(n%2==0)n/=2;
			else n=n*3+1;
			m++;
		}
		if(m>ans)ans=m;
	}
	cout<<ans;
	
	return 0;
} 
