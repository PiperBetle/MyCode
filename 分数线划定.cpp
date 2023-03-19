#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int a[5050];
string b[5050],tt;
int main()
{
	int i,j,t,n,m,luqv,num;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>b[i]>>a[i];
	m=m*1.5;
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				tt=b[j];
				b[j]=b[j+1];
				b[j+1]=tt;
			}
			else
			{
				if((a[j]==a[j+1])&&(b[j]>b[j+1]))
				{
					t=a[j];
					a[j]=a[j+1];
					a[j+1]=t;
					tt=b[j];
					b[j]=b[j+1];
					b[j+1]=tt;
				}
			}
		}
	}
	luqv=a[m];
	num=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=luqv)
		{
			num++;
		}
		else
		{
			break;
		}
	}
	cout<<luqv<<" "<<num<<endl;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=luqv)
		{
			cout<<b[i]<<" "<<a[i]<<endl;
		}
		else
		{
			break;
		}
	}
	
	return 0;
}
