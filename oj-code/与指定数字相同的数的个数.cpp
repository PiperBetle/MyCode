#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	int m,a[101],num=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(i=1;i<=n;i++)if(a[i]==m)num++;
	cout<<num; 
	
	return 0;
} 
