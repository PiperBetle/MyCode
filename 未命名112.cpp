#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i,j,k,temp,kk;
	int a[101];
	string b[101],t;
	int m,n;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]; 
	}
	for (i=1;i<=n-1;i++)
	{
		k=kk=i;
		for (j=i+1;j<=n;j++) 
		{
			if (a[j]<a[k]) k=j;
			else if(a[j]=a[k])
		}
			
		if (k!=i) 
		{
			temp=a[k];
			a[k]=a[i];
			a[i]=temp;
			t=b[k];
			b[k]=b[i];
			b[i]=t;
		}
	}	
	cout<<a[m]<<" "<<b[m]<<endl;
	
	return 0;
} 
