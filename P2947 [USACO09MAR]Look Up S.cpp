#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<stack>
using namespace std;
int a[100007],b[100007]={0};
int main()
{
	int n,m,t;
	int i,j,k;
	
	cin>>n;
	a[0]=199999999;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n;i>1;i--)
	{
		t=i;
		while(a[i-1]>=a[t])t=b[t];
		b[i-1]=t;
	}
	for(i=1;i<=n;i++)cout<<b[i]<<'\n';
	
	return 0;
}
