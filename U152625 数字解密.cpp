#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char qq[1007];
int p[1007],q[1007];
int main()
{
	int i,j,k;
	int n,m,t,len;
	
	scanf("%s",qq);
	if((strlen(qq)==1)&&(qq[0]!='0'))
	{
		puts("NONE");
		puts("NONE");
		return 0;
	}
	len=strlen(qq);
	for(i=0;i<len;i++)q[i+1]=qq[i]-'0';
//	puts(qq);
	
	p[1]=0;
	p[2]=q[1]-p[1];
	for(i=2;i<=len-1;i++)p[i+1]=q[i]-p[i]-p[i-1];
	if((q[n]-p[n-1])!=(q[n-1]-p[n-1]-p[n-2]))puts("NONE");
	else
	{
		p[n]=q[n]-p[n-1];
		int flag=1;
		for(i=1;i<=len;i++)if((p[i]!=0)&&(p[i]!=1))flag=0;
		for(i=1;i<=len;i++)if(q[i]!=p[i-1]+p[i]+p[i+1])flag=0;
		if(flag)for(i=1;i<=len;i++)cout<<p[i];
		else cout<<"NONE";
		putchar('\n');
	}
	
	for(i=0;i<1007;i++)p[i]=0;
	p[1]=1;
	p[2]=q[1]-p[1];
	for(i=2;i<=len-1;i++)p[i+1]=q[i]-p[i]-p[i-1];
	if((q[n]-p[n-1])!=(q[n-1]-p[n-1]-p[n-2]))cout<<"NONE";
	else
	{
		p[n]=q[n]-p[n-1];
		int flag=1;
		for(i=1;i<=len;i++)if((p[i]!=0)&&(p[i]!=1))flag=0;
		for(i=1;i<=len;i++)if(q[i]!=p[i-1]+p[i]+p[i+1])flag=0;
		if(flag)for(i=1;i<=len;i++)cout<<p[i];
		else cout<<"NONE";
	}
	
	return 0;
}
