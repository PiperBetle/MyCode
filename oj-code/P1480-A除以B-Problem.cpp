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
struct bigint
{
	vector<int> num;
	void ament(string s)
	{
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(int i=0;i<num.size();i++)
			num[i]=s[i]-48;
	}
	void read()
	{
		string s;
		cin>>s;
		ament(s);
	}
	void write()
	{
		cout<<num[num.size()-1];
		for(int i=num.size()-2;i>=0;i--)
			cout<<num[i];
		cout<<'\n';
	}
	bigint operator /(const int &n)
	{
		bigint c;
		int rest=0;
		c.num.resize(num.size());
		for(int i=num.size();i--;rest*=10)
		{
			rest+=num[i];
			c.num[i]=rest/n;
			rest%=n;
		}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
};
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	bigint n;
	int m;

	n.read();
	cin>>m;
	(n/m).write();

	return 0;
}