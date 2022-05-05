#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007],b[1007],f[1007];
int lc[1007],c[1007][1007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int num=0;
	 
	
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>t;
		num=max(num,t);
		lc[t]++;
		c[t][lc[t]]=i;
	}
	for(i=1;i<=num;i++)
		for(j=m;j>=0;j--)
			for(k=1;k<=lc[i];k++)
				if(j>=a[c[i][k]])
					f[j]=max(f[j],f[j-a[c[i][k]]]+b[c[i][k]]);
	cout<<f[m];
	
	return 0;
}
