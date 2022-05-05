#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	char aa[101];
	int a[101],la,i,j,k,t;
	string s="none",st="";
	
	for(i=0;i<=100;i++)a[i]=aa[i]=0;
	gets(aa);
	la=strlen(aa);
	for(i=0;i<=la;i++)a[la-i]=aa[i]-'0';
	for(i=2;i<=9;i++)
	{
		t=0;
		for(j=la;j>=1;j--)
		{
			t=10*t+a[j];
			t=t%i;
		}
		if(t==0)
		{
			s="";
			cout<<st<<i;
			st=" ";
		}
	}
	cout<<s;
	
	return 0;
}
