#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<ext/rope>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
using namespace __gnu_cxx;
string s;
rope<char> a;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	char c;
	int p;
	
	cin>>s;
	n=s.length();
	a.push_back(' ');
	for(i=0;i<n;i++)
		a.push_back(s[i]);
	cin>>T;
	while(T--)
	{
		cin>>c;
		if(c=='I')
		{
			cin>>c>>p;
			if(p>a.length())a.push_back(c);
			else a.insert(p,c);
		}
		else
		{
			cin>>p;
			cout<<a[p]<<'\n';
		}
	}
	
	return 0;
}