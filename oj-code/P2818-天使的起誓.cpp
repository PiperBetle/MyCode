#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
string a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;

	cin>>n>>a;
	j=a.length();
	for(i=0;i<j;i++)
		ans=(ans*10+a[i]-'0')%n;
	if(ans==0)
		cout<<n;
	else
		cout<<ans;

	return 0;
}