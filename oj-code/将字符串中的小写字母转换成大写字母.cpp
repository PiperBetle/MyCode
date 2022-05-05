#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
string a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>a;
	for(i=0;i<a.length();i++)
		if('a'<=a[i]&&a[i]<='z')
			a[i]=a[i]-'a'+'A';
	cout<<a;
	
    return 0;
}
