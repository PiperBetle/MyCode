#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
string a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m=0,t;
	
	cin>>a;
	for(i=0;i<a.length();i++)
		m=max(m,a[i]-'0');
	cout<<m<<'\n';
	for(k=1;k<=m;k++)
	{
		string s="";
		for(i=0;i<a.length();i++)
			if(a[i]>'0')
			{
				a[i]--;
				s+="1";
			}
			else s+="0";
		for(i=0;i<s.length();i++)
			if(s[i]!='0')
				break;
		for(;i<s.length();i++)
			cout<<s[i];
		cout<<' ';
	}
	
	return 0;
}
