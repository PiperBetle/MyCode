#include<iostream>
using namespace std;
int main()
{
	int i,j,num,n,t,a[200],flag=0,temp;//50~150(+100)
	
	cin>>n;
	for(i=50;i<=150;i++)a[i]=0;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		a[t+100]++;
	}
	num=n/2;
	for(i=50;i<=150;i++)
	{
		if(a[i]>num)
		{
			cout<<i-100;
			flag=1;
			break;
		}
	}
	if(!flag)cout<<"no";
	
	return 0;
}
