#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int f[32007];
int Mw[32007],Mc[32007];
int Aw[32007][3],Ac[32007][3];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,v,p,q;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>v>>p>>q;
		if(!q)
		{
			Mw[i]=v;
			Mc[i]=v*p;
		}
		else
		{
			Aw[q][0]++;
			Aw[q][Aw[q][0]]=v;
			Ac[q][Aw[q][0]]=v*p;
		}
	}
	for(i=1;i<=m;i++)
		for(j=n;j>=Mw[i];j--)
		{
			f[j]=max(f[j],f[j-Mw[i]]+Mc[i]);
			if(j>=Mw[i]+Aw[i][1])f[j]=max(f[j],f[j-Mw[i]-Aw[i][1]]+Mc[i]+Ac[i][1]);
			if(j>=Mw[i]+Aw[i][2])f[j]=max(f[j],f[j-Mw[i]-Aw[i][2]]+Mc[i]+Ac[i][2]);
			if(j>=Mw[i]+Aw[i][1]+Aw[i][2])f[j]=max(f[j],f[j-Mw[i]-Aw[i][1]-Aw[i][2]]+Mc[i]+Ac[i][1]+Ac[i][2]);
		}
	cout<<f[n];
	
	return 0;
}
