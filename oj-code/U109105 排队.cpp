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
	char a[21][51];
	int len[21],now[21],i,j,n=1,jk=0,small,smallchar;
	
	while(gets(a[n]))
	{
		n++;
	}
	n--;
	for(i=1;i<=n;i++)
	{
		now[i]=1;
		len[i]=strlen(a[i]);
		jk+=len[i];
	}
	while(jk)
	{
		for(i=1;i<=n;i++)
		{
			if(len[i]!=now[i])
			{
				if(a[i][now[i]]<a[small][now[small]])
				{
					small=i;
				}
			}
		}
		cout<<a[small][now[small]];
		now[small]++;
		jk--;
	}
	
	return 0;
}
