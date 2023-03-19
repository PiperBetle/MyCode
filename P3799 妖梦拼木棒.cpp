#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define MOD 1000000007
using namespace std;
int a[1000007];
int b[50007];
int C(int x)
{
	return x*(x-1)/2%MOD;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=-1,t;
	int ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		m=max(m,a[i]);
		b[a[i]]++;
	}
	for(i=1;i<=m;i++)
		for(j=i;j<=m;j++)
			if(i==j)ans=(ans+C(b[i])*C(b[i+j]))%MOD;
			else ans=(ans+(b[i]*b[j]%MOD*C(b[i+j]))%MOD)%MOD;
	cout<<ans;
	
	return 0;
}
