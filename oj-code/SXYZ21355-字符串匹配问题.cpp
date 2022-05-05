#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[301];
int a[301],b[301],la,lb=0;
int qw(char c)
{
	if(c=='{')return 1;
	if(c=='[')return 2;
	if(c=='(')return 3;
	if(c=='<')return 4;
	if(c=='>')return 5;
	if(c==')')return 6;
	if(c==']')return 7;
	if(c=='}')return 8;
	return 0;
}
int main()
{
//	freopen("strs.in","r",stdin);
//	freopen("strs.out","w",stdout);
	int n,T;
	int i,j,k;
	int a1,a2,a3,a4;
	bool flag;
	
	scanf("%d",&T);
	while(T--)
	{
		lb=0;
		for(i=0;i<=300;i++)a[i]=b[i]=c[i]=0;
		scanf("%s",c);
		la=strlen(c);
		for(i=0;i<la;i++)a[i]=qw(c[i]);
		for(i=0;i<la;i++)
			if(a[i]<=4)
			{
				if(a[i]>=b[lb])
					b[++lb]=a[i];
				else
					break;
			}
			else
			{
				if(a[i]+b[lb]==9)
					lb--;
				else
					lb++;
			}
		if(lb)puts("NO");
		else puts("YES");
	}
	
	return 0;
}