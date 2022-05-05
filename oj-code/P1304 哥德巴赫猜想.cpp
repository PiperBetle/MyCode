#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool prime(int n)
{
	int i;
	if(n==2)return 1;
	if(n%2==0)return 0;
	if(n<=1)return 0;
	for(i=3;i*i<=n;i++)
		if(n%i==0)return 0;
	return 1;
}
int main()
{
	int n,i,j,a,b;

	cin>>n;
	for(i=4;i<=n;i+=2)
	{
		cout<<i<<"=";
		if(i==4)cout<<"2+2"<<endl;
		else
		{
			for(j=3;;j+=2)
			{
				a=j;
				b=i-j;
				if((prime(a)==1)&&(prime(b)==1))
				{
					cout<<a<<"+"<<b<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}
