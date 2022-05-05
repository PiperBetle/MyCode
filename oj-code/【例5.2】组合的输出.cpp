#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int n,m,a[101],b[101],c;
void pr()
{
	for(int i=1;i<=m;i++)cout<<setw(3)<<a[i];
	cout<<endl;
}
void s(int min,int t)
{
	for(int i=min+1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[t]=i;
			b[i]=1;
			if(t==m)pr();
			s(i,t+1);
			b[i]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	s(0,1);
	c=n;
	while(c--)b[c]=a[c]=0;
	
	return 0;
}
