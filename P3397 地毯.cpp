#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
int a[1007][1007];
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int x1,x2,y1,y2;
	
	cin>>n>>m;
	while(m--)
	{
		cin>>x1>>y1>>x2>>y2;
		for(i=x1;i<=x2;i++)
			for(j=y1;j<=y2;j++)
				a[i][j]++;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n+1;j++)
			if(j<=n)cout<<a[i][j]<<" ";
			else cout<<"\n";
	
	return 0;
}
