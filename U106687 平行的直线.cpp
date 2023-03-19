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
int s(int a,int b)
{
	if(b==0)return a;
	return s(b,a%b);
}
int gcd(int a,int b)
{
	if((a*b)>0)return s(a,b);
	else return -(abs(a),abs(b));
}
int main()
{
	int len1=0,len2=0,n,i,j,a[50001][2],b[50001][2],ml,m,x[250],y[250],qw1,qw2;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++)
		{
			qw1=y[j]-y[i];
			qw2=x[j]-x[i];
			if(qw2!=0)
			{
				len1++;
				ml=gcd(qw1,qw2);
				a[len1][1]=qw1/ml;
				a[len1][2]=qw2/ml;
			}
		}
	for(i=1;i<=len1;i++)
	{
		ml=1;
		for(j=1;j<=len2;j++)
			if((a[i][1]==b[j][1])&&(a[i][2]==b[j][2]))
			{
				ml=0;
				break;
			}
		if(ml)
		{
			len2+=1;
			b[len2][1]=a[i][1];
			b[len2][2]=a[i][2];
		}
	}
	cout<<len2;
	
	return 0;
}
