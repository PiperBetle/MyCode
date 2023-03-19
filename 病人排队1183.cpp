#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,a[101],b[101],c[101],t,lb,lc;
	string aa[101],bb[101],cc[101],tt;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>aa[i]>>a[i];
	}
	lb=lc=0;
	for(i=1;i<=n;i++)
	{
		if(a[i]>=60)
		{
			lb++;
			bb[lb]=aa[i];
			b[lb]=a[i];
		}
		else
		{
			lc++;
			cc[lc]=aa[i];
			c[lc]=a[i];
		}
	}
	for(i=1;i<=lb-1;i++)
	{
		for(j=1;j<=lb-i;j++)
		{
			if(b[j]<b[j+1])
			{
				t=b[j];
				b[j]=b[j+1];
				b[j+1]=t;
				tt=bb[j];
				bb[j]=bb[j+1];
				bb[j+1]=t;
			}
		}
	}
	for(i=1;i<=lb;i++)
	{
		cout<<bb[i]<<" "<<b[i]<<endl;
	}
	for(i=1;i<=lc;i++)
	{
		cout<<cc[i]<<" "<<c[i]<<endl;
	}
	
	return 0;
}
