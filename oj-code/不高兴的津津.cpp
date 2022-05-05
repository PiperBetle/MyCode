#include<iostream>
using namespace std;
int main()
{
	int a,b,i,max=-1,tpmax=0;
	
	for(i=1;i<=7;i++)
	{
		cin>>a>>b;
		if((a+b)>max)
		{
			max=a+b;
			tpmax=i;
		}
	}
	cout<<tpmax;
}
