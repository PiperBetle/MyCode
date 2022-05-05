#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string s;
char a[1007][1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=5;i++)
		for(j=1;j<=n*4+1;j++)
			a[i][j]='.';
	for(i=1;i<=n;i++)
	{
		a[3][i*4-1]=s[i-1];
		a[3][i*4-3]='#';
		a[3][i*4+1]='#';
		a[2][i*4-2]='#';
		a[2][i*4]='#';
		a[4][i*4-2]='#';
		a[4][i*4]='#';
		a[1][i*4-1]='#';
		a[5][i*4-1]='#';
	}
	for(i=3;i<=n;i+=3)
	{
		a[3][i*4-3]='*';
		a[3][i*4+1]='*';
		a[2][i*4-2]='*';
		a[2][i*4]='*';
		a[4][i*4-2]='*';
		a[4][i*4]='*';
		a[1][i*4-1]='*';
		a[5][i*4-1]='*';
	}
	for(i=1;i<=5;i++)
		for(j=1;j<=n*4+1;j++)
			if(j==n*4+1)cout<<a[i][j]<<'\n';
			else cout<<a[i][j];
	
    return 0;
}
