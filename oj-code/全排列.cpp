#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int len;
void pai(char a[],int p)
{
	
}
int main()
{
	int i,j,k,n,m;
	char b[51],a[51];
	
	for(i=1;i<=50;i++)a[i]=b[i]=0;
	gets(b);
	len=strlen(b);
	for(i=1;i<=len+1;i++)a[i]=b[i-1];
	pai(b,0);
	
	return 0;
}
