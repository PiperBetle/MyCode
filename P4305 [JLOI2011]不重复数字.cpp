#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
bool a[214748360];
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(a,0,sizeof a);
		for(i=1;i<=n;i++)
		{
			cin>>k;
			if(a[k]==0)
			{
				a[k]=1;
				cout<<k<<" ";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
