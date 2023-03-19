#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define MOD 100003
using namespace std;
int a[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>k;
	a[0]=a[1]=1;
	for(i=2;i<=n;i++)
		if(i<=k)a[i]=a[i-1]*2%MOD;
		else a[i]=(a[i-1]*2-a[i-k-1])%MOD;
	cout<<(a[n]+MOD)%MOD;
	
	return 0;
}
