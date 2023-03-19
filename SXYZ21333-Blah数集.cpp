#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[10000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	while(cin>>m>>n)
	{
		a[1]=m;
		int _1=1,_2=1;
		for(i=2;i<=n;i++)
		{
			m=min(2*a[_1]+1,3*a[_2]+1);
			a[i]=m;
			if(m==2*a[_1]+1)
				_1++;
			else
				_2++;
			if(a[i]==a[i-1])
				i--;
		}
		cout<<a[n]<<'\n';
	}
	
	return 0;
}