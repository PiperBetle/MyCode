#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
string a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m=0,ans=0;
	
	cin>>n>>a;
	for(i=0;i<n-1;i++)
		if(a[i]=='V'&&a[i+1]=='K')
		{
			ans++;
			a[i]='~';
			a[i+1]='~';
		}
	for(i=0;i<n-1;i++)
		if((a[i]==a[i+1])&&(a[i]!='~'))
			m=1;
	cout<<ans+m;
	
    return 0;
}
