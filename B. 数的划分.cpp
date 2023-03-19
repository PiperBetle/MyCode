#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long a[301][21];
int main()
{
	int n,m,p;
	int i,t;
	int p1,p2,s1,s2;
	int j,k;
	
	a[0][0]=1;
	cin>>n>>k;
	for(i=1;i<=n;i++)for(j=1;j<=k;j++)if(i>=j)a[i][j]=a[i-j][j]+a[i-1][j-1];
	cout<<a[n][k];
	
	return 0;
}
