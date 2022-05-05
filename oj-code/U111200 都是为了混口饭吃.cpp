#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long i,j,n,m,m1,m2,p,f[1000007],pre[1000007],a[1000007],b[1000007],num[1000007],w[1000007],v[1000007];
int main()
{
	int i,j,k;
	int n,m,t,T,sum1=0,sum2=0;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)
	{
		v[i]=a[i];
		w[i]=b[i]-a[i];
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>0)
		{
			for(j=v[i];j<=m;j++)
			{
				if(f[j-v[i]]+w[i]>f[j])
				{
					f[j]=f[j-v[i]]+w[i];
					pre[j]=i;
				}
			}
		}
	}
	m1=f[m]+m;
	p=m;
	while(pre[p]!=0)
	{
		num[pre[p]]--;
		p=p-v[pre[p]];
	}
	for(i=0;i<1000000;i++)f[i]=pre[i]=0;
	for(i=1;i<=n;i++)
	{
		v[i]=b[i];
		w[i]=a[i]-b[i];
	}
	for(i=1;i<=n;i++)
	{
		if(w[i]>0)
		{
			for(j=v[i];j<=m1;j++)
			{
				if(f[j-v[i]]+w[i]>f[j])
				{
					f[j]=f[j-v[i]]+w[i];
					pre[j]=i;
				}
			}
		}
	}
	m2=m1+f[m1];
	p=m1;
	while(pre[p]!=0)
	{
		num[pre[p]]--;
		p=p-v[pre[p]];
	}
	cout<<m2-m<<endl;
	for(i=1;i<=n;i++)
	{
		if(num[i]!=0)
		{
			cout<<"Buy "<<-num[i];
			if(a[i]>b[i])cout<<" from Skellige";
			if(a[i]<b[i])cout<<" from Toussaint";
		}
		else
		{
			cout<<"Buy 0";
		}
		cout<<endl;
	}
	
	return 0;
}
