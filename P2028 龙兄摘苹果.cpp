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
unsigned long long a[10001][1001]={0};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	unsigned long long n,m,i,j,k,p;
	
//	a[0][1]=1;
	cin>>n>>m>>p;
	for(i=1;i<=n;i++)
	{
		a[i][1]=1;
		for(j=2;j<=m;j++)
		{
			a[i][j]=(((j%p)*(a[i-1][j]%p)%p)+a[i-1][j-1]%p)%p;
		}
	}
	cout<<a[n][m]<<endl;
	
	return 0;
}
