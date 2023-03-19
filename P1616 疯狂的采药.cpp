#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
long long w[100005],f[10000005],c[100005];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,v;
	
	cin>>v>>n;
	for(i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=w[i];j<=v;j++)
		{
			f[j]=max(f[j-w[i]]+c[i],f[j]);
		}
	}
	cout<<f[v];
	
	return 0;
}
