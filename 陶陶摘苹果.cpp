#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int i,j,n,m,t;
	int a[11],b,c,d,num=0;
	
	for(i=1;i<=10;i++)cin>>a[i];
	cin>>b;
	b+=30;
	for(i=1;i<=10;i++)if(b>=a[i])num++;
	cout<<num;
	
	return 0;
} 
