#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,n,m,i,j,k;
	string t="";
	
	cin>>m;
	for(i=2;i<=m;i++)
	{
		if(m<=i)break;
		else
		{
			a=0;
			while(!(m%i))
			{
				m=m/i;
				a++;
			}
			if(a)
				if(a==1)
				{
					cout<<t<<i;
					t="*";
				}
				else
				{
					cout<<t<<i<<'^'<<a;
					t="*";
				}
		}
	}
	if(m!=1)cout<<t<<m;
	
	return 0;
}
