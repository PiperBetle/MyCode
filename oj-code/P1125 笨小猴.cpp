#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool prime(int n)
{
	if(n<2)return 0;
	if(n<=3)return 1;
	for(int i=2;i*i<=n;i++)
		if(n%i==0)return 0;
	return 1;
}
int main()
{
	char a[1001];
	int	len,num[27]={0},maxn=0,minn=0,i;

	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++)
	{
		num[a[i]-'a'+1]++;
	}
	maxn=-1;
	minn=10001;
	for(i=1;i<27;i++)
	{
		if(num[i]>=1)
		{
			if(num[i]>maxn)maxn=num[i];
			if(num[i]<minn)minn=num[i];
		}
	}
	if(prime(maxn-minn)==1)
	{
		cout<<"Lucky Word"<<endl<<maxn-minn;
	}
	else
	{
		cout<<"No Answer"<<endl<<0;
	}
	
	return 0;
}

