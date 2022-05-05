#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[200001],maxx[200001],n,qwq,maxn,t,tt,i,j;
	
	for(i=0;i<=200000;i++)
		a[i]=maxx[i]=0;
	qwq=0;		
		
	cin>>n;
	for(j=1;j<=n;j++)
	{
		cin>>tt;
		if(tt==0)
		{
			cin>>t;
			qwq++;
			a[qwq]=t;
			maxx[qwq]=max(maxx[qwq-1],a[qwq]);
		}
		else
		{
			if(tt==1)
			{
				if(qwq!=0)
				{
					qwq--;
				}
			}
			else
			{
				if(qwq==0)cout<<0<<endl;
				else
				{
					cout<<maxx[qwq]<<endl;
				}
			}
		}
	}
	
	return 0;
}
