#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	
	int i,j,k,flag,a[11],x,y,z,a1,a2,a3,symbol=1;
	
	cin>>a1>>a2>>a3;
	for(i=1;i<=333;i++)
	{
		flag=1;
		x=i*a1;
		y=i*a2;
		z=i*a3;
		for(k=1;k<=9;k++)
		{
			a[k]=0;
		}
		a[x%10]++;
		x/=10;
		a[x%10]++;
		x/=10;
		a[x%10]++;
		
		a[y%10]++;
		y/=10;
		a[y%10]++;
		y/=10;
		a[y%10]++;
		
		a[z%10]++;
		z/=10;
		a[z%10]++;
		z/=10;
		a[z%10]++;
		
		for(k=1;k<=9;k++)
		{
			if(a[k]!=1)
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			cout<<i*a1<<" "<<i*a2<<" "<<i*a3<<endl;
			symbol=0;
		}
	}
	if(symbol==1)cout<<"No!!!";

	return 0;
}
