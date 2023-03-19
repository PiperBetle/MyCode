#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
struct qw
{
	int begin,lasts;
};
qw a[10007];
int sum[10007],f[10007],n,k;
int cmp(qw a,qw b)
{
	return a.begin>b.begin;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j;
	int m,t,x=1,y;
	char c;
	
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		cin>>a[i].begin>>a[i].lasts;
		sum[a[i].begin]++;
	}
	sort(a+1,a+1+k,cmp);
	for(i=n;i>=1;i--)
	{
		if(sum[i]==0)f[i]=f[i+1]+1;
		else
			for(j=1;j<=sum[i];j++)
			{
				f[i]=max(f[i],f[i+a[x].lasts]);
				x++;
			}
	}
	cout<<f[1];
	
	return 0;
}
