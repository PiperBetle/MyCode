#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
string a;
int len;
int c(int n,int m)
{
	if(n==0)
		return 1;
	int ans=1,i;
	for(i=m-n+1;i<=m;i++)
		ans*=i;
	for(i=1;i<=n;i++)
		ans/=i;
	return ans;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0;

	cin>>a;
	len=a.length();
	for(i=1;i<len;i++)
		if(a[i]<=a[i-1])
		{
			cout<<0;
			return 0;
		}
	for(i=0;i<len;i++)
		ans+=c(i,26);
	for(i=0;i<len;i++)
		for(j=(i==0?'a':a[i-1]+1);j<a[i];j++)
			ans+=c(len-i-1,'z'-j);
	cout<<ans<<'\n';

	return 0;
}