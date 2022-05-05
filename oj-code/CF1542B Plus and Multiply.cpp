#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int a,b,t;
	
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b;
		if(a==1)
			if(n%b==1||n==1||b==1)cout<<"Yes\n";
			else cout<<"No\n";
		else
		{
			string ans="No\n";
			for(i=1;i<=n;i*=a)
				if((n-i)%b==0)ans="Yes\n";
			cout<<ans;
		}
	}
	
	return 0;
}
