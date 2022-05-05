#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,m,t,i;
	float b;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		m+=t;
	}
	b=(float)m/(float)n;
	printf("%.2f",(float)b);
	
	return 0;
}
