#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k=1;
	int n,m=0,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		ans+=k;
		if(i==(1+k)*k/2)k++;
	}
	cout<<ans;
	
    return 0;
}
