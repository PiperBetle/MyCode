#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[4],i,j,k,x,y,z;
	
	cin>>a[1]>>a[2]>>a[3];
	x=min(min(a[1],a[2]),a[3]);
	z=max(max(a[1],a[2]),a[3]);
	y=a[1]+a[2]+a[3]-x-z;
	i=x*x+y*y-z*z;
	if((x+y)<=z)
	{
		cout<<"Not triangle"<<endl;
	}
	else
	{
		if(i==0)
		{
			cout<<"Right triangle"<<endl;
		}
		if(i>0)
		{
			cout<<"Acute triangle"<<endl;
		}
		if(i<0)
		{
			cout<<"Obtuse triangle"<<endl;
		}
		if((x==z)||(y==z)||(x==y))
		{
			cout<<"Isosceles triangle"<<endl;
		}
		if((x==z)&&(y==z))
		{
			cout<<"Equilateral triangle"<<endl;
		}
	}
	
	
	return 0;
}
