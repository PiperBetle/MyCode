#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,b[21],t;
	string a[21],tt;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(b[j]<b[j+1])
			{
				tt=a[j];
				a[j]=a[j+1];
				a[j+1]=tt;
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
			}
			else
			{
				if(b[j]==b[j+1])
				{
					if(a[j]>a[j+1])
					{
						tt=a[j];
						a[j]=a[j+1];
						a[j+1]=tt;
						t=b[j];
						b[j]=b[j+1];
						b[j+1]=t;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<endl;
	
	return 0;
}
