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
int main()
{
	char a[21][101];
	int len[21],n,i,j,k,maxn=1;
	
	for(i=0;i<=20;i++)
	{
		len[i]=0;
		for(j=0;j<=100;j++)a[i][j]=0;
	}
	cin>>n;
	getchar();
	for(i=1;i<=n;i++)
	{
  	scanf("%s",a[i]);
		len[i]=strlen(a[i]);
	}
	for(i=2;i<=n;i++)
	{
		if(len[i]>len[maxn])maxn=i;
		else
		{
			if(len[i]==len[maxn])
			{
				for(j=0;j<len[i];j++)
				{
					if(a[i][j]>a[maxn][j])
					{
						maxn=i;
						break;
					}
					else
					{
						if(a[i][j]<a[maxn][j])
						{
							break;
						}
					}
				}
			}
		}
	}
	cout<<maxn<<endl;
	for(i=0;i<len[maxn];i++)cout<<a[maxn][i];
	
	return 0;
}
