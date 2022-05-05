#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):-(a))
#define M 32768
using namespace std;
int f[40007][5]={1};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=1;i*i<=M;i++)
		for(j=i*i;j<=M;j++)
			for(k=1;k<=4;k++)
				f[j][k]+=f[j-i*i][k-1];
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<f[n][1]+f[n][2]+f[n][3]+f[n][4]<<endl;
	}
	
	return 0;
}
