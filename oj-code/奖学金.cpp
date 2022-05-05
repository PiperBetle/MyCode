#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int a[301],b[301],c[301],d[301],num[301],n,m,i,j,k;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		num[i]=i;
		cin>>a[i]>>b[i]>>c[i];
		d[i]=a[i]+b[i]+c[i];
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(d[j]<d[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
				swap(c[j],c[j+1]);
				swap(d[j],d[j+1]);
				swap(num[j],num[j+1]);
			}
			else
			{
				if((d[j]==d[j+1])&&(a[j]<a[j+1]))
				{
					swap(a[j],a[j+1]);
					swap(b[j],b[j+1]);
					swap(c[j],c[j+1]);
					swap(d[j],d[j+1]);
					swap(num[j],num[j+1]);
				}
				else
				{
					if((d[j]==d[j+1])&&(a[j]==a[j+1])&&(num[j]>num[j+1]))
					{
						swap(a[j],a[j+1]);
						swap(b[j],b[j+1]);
						swap(c[j],c[j+1]);
						swap(d[j],d[j+1]);
						swap(num[j],num[j+1]);
					}
				}
			}
		}
	}
	for(i=1;i<=5;i++)
		cout<<num[i]<<" "<<d[i]<<endl;
	
	return 0;
}
