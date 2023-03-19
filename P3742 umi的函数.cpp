#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#define int long long
using namespace std;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m=0,t;
	string a,b,c;
	
	cin>>n>>a>>c;
	for(i=0;i<n;i++)
		if(c[i]>a[i])
		{
			cout<<-1;
			return 0;
		}
	cout<<c;
	
    return 0;
}
