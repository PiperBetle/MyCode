#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int ans=0;
	char c;
	
	for(i=1;i<=8;i++)
	{
		cin>>c;
		if(c=='1')ans++;
	}
	cout<<ans;
	
	return 0;
}
