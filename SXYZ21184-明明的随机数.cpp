#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool b[1007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,cnt=0;
	
	cin>>n;
	while(n--)
	{
		cin>>k;
		b[k]=1;
	}
	for(i=1;i<=1000;i++)
		if(b[i])
			cnt++;
	cout<<cnt<<'\n';
	for(i=1;i<=1000;i++)
		if(b[i])
			cout<<i<<' ';
	
	return 0;
}