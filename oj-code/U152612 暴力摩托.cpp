#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
double m,f[1010];
int main()
{
	int i,j,k;
	
	cin>>n>>m;
	n/=10;
	for(i=1;i<=n;i++)
	{
		if(i<=1)f[i]=i/10.0;
		else if(i<=2)f[i]=i/9.0;
		else if(i<=3)f[i]=i/8.0;
		else if(i<=4)f[i]=i/7.5;
		else f[i]=i/7.0;
		for(j=1;j<i;j++)
		{
			double ans=m/60.0,t=i-j;
			if(t<=1) ans=ans+t/10.0;
			else if(t<=2) ans=ans+t/9.0;
			else if(t<=3) ans=ans+t/8.0;
			else if(t<=4) ans=ans+t/7.5;
			else ans=ans+t/7.0;
			f[i]=min(f[i],f[j]+ans);
		}
	}
	printf("%.2lf",f[n]);
	
	return 0;
}
