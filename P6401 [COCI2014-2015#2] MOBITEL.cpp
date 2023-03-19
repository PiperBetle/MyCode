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
using namespace std;
int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int pp[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int main()
{
	char c[1001];
	int i,j,k,a[11],len,t;
	
	for(i=1;i<=9;i++)
	{
		cin>>k;
		a[k]=i;
	}
	scanf("%s",c);
	len=strlen(c);
	k=-1;
	for(i=0;i<len;i++)
	{
		j=a[pp[c[i]-'a']];
		if(j==k)putchar('#');
		for(t=1;t<=num[c[i]-'a'];t++)cout<<j;
		k=j;
	}
	
    return 0;
}
