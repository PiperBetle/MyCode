#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
//	freopen("unhappy.in","r",stdin);
//	freopen("unhappy.out","w",stdout);
	int i,j,k;
	int n,m,maxn=8,day=0;
	
	for(i=1;i<=7;i++)
	{
		cin>>n>>m;
		n+=m;
		if(n>maxn)
		{
			day=i;
			maxn=n;
		}
	}
	cout<<day;
	
    return 0;
}
