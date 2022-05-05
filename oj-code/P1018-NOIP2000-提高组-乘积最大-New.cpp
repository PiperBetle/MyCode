#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
string s;
int f[107][107][107];
int temp[107];
int ans[107];
int comp(int x[],int y[])// x<y re 0
{
	if(x[0]<y[0])return 0;
	if(x[0]>y[0])return 1;
	for(int i=x[0];i>=1;i++)
	{
		if(x[i]<y[i])return 0;
		if(x[i]>y[i])return 1;
	}
}
void times(int a[],int b[],int c[])
{
	c[0]=a[0]+b[0];
	for(int i=1;i<=a[0];i++)
	{
		for(int j=1;j<=b[0];j++)
		{
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	for(int i=c[0];i>=1;i--)
	{
		if(c[i]!=0)break;
		c[0]--;
	}
	if(c[0]==0)c[0]++;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int _1,_2,_3;
	
	cin>>n>>t;
	cin>>s;
	s="0"+s;
	for(i=0;i<n;i++)
	{
		f[0][i][0]=i;
		for(j=1;j<=i;j++)f[0][i][j]=s[i-j+1]-'0';
	}
	for(i=1;i<=t;i++)
        for(j=1;j<=n;j++)
            for(k=j;k>=i;k--)
            {
            	memset(temp,0,sizeof temp);
            	memset(ans,0,sizeof ans);
            	temp[0]=j-k+1;
            	for(_1=k;_1<=j;_1++)
            		temp[_1]=s[j-_1+k];
            	times(f[i-1][k-1],temp,ans);
            	if(!comp(f[i][j],ans))
            	{
            		memset(f[i][j],0,sizeof f[i][j]);
            		for(_1=0;_1<=ans[0];_1++)
            			f[i][j][_1]=ans[_1];
				}
			}
	for(i=1;i<=100;i++)
		printf("%.0Lf",f[t][n-1][i]);
	
	return 0;
}
