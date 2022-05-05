#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,n,i;
	
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n;
		cout<<a/b<<'.';
		a=a%b;
		for(i=1;i<=n;i++)
		{
			a*=10;
			cout<<a/b;
			a=a%b;
		}
		cout<<endl;
	}
	
	return 0;
} 
