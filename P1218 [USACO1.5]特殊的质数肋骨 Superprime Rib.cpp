#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
int a[101][101]={0};
bool prime(int nn);
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k,t,n;
	
	scanf("%d",&n);
	a[1][1]=2;
	a[1][2]=3;
	a[1][3]=5;
	a[1][4]=7;
	a[1][0]=4;
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=a[i-1][0];j++)
		{
			for(k=1;k<=9;k++)
			{
				t=a[i-1][j]*10+k;
//				cout<<t<<endl;
				if(prime(t))
				{
					a[i][0]++;
					a[i][a[i][0]]=t;
				}
			}
		}
	}
	for(i=1;i<=a[n][0];i++)printf("%d\n",a[n][i]);
	
	return 0;
}
bool prime(int n)
{
	if(n<2)return 0;
	int i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
