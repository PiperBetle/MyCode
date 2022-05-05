#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int i,j,n,c['z'+1],max;
	char a[2000],maxchar;
	
	for(i='a';i<='z';i++)c[i]=0;
	gets(a);
	n=strlen(a);
	for(i=0;i<=n-1;i++)
	{
		c[a[i]]++;
	}
	max=c['a'];
	maxchar='a';
	for(i='b';i<='z';i++)
	{
		if(max<c[i])
		{
			max=c[i];
			maxchar=i;
		}
	}
	cout<<maxchar<<" "<<max;
	
	return 0;
}
