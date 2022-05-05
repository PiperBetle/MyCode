#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#define MOD 100003
using namespace std;
string read()
{
	char c;
	string s="";
	while(cin>>c)
	{
		if(c==']')return s;
		if(c=='[')
		{
			int n;
			cin>>n;
			string st;
			st=read();
			while(n--)s+=st;
		}
		else s+=c;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cout<<read();
	
	return 0;
}
