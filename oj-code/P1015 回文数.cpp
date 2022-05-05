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
int qw(int a[],int len)
{
	int i;
	for(i=1;i<=len/2+1;i++)
	{
		if(a[i]!=a[len-i+1])return 0;
	}
	return 1;
}
int main()
{
	char aa[10001]={0};
	int a[10001]={0},i,j,k,n,len,t[10001]={0};
	
	cin>>n;
	scanf("%s",aa);
	len=strlen(aa);
	for(i=0;i<=len-1;i++)
	{
		a[i+1]=aa[len-i-1];
		if(('0'<=a[i+1])&&(a[i+1]<='9'))a[i+1]-='0';
		else a[i+1]=a[i+1]-'A'+10;
	}
	for(i=0;i<30;i++)
	{
		if(qw(a,len)==1)
		{
			cout<<"STEP="<<i;
			return 0;
		}
		for(j=1;j<=len;j++)
		{
			t[j]=a[len-j+1];
		}
		for(j=1;j<=len;j++)
		{
			a[j]+=t[j];
			a[j+1]=a[j+1]+a[j]/n;
			a[j]%=n;
		}
		if(a[len+1]>0)len++;
//		cout<<i+1<<endl;
//		for(j=1;j<=len;j++)cout<<a[j];
	}
	cout<<"Impossible!";
	
	return 0;
}
