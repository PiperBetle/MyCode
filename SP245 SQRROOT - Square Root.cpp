#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
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
	bigint operator +(const bigint &n)
	{
		bigint c;
		c.num.resize(max(num.size(),n.num.size())+1);
		for(int i=0;i<num.size();i++)
			c.num[i]+=num[i];
		for(int i=0;i<n.num.size();i++)
			c.num[i]+=n.num[i];
		for(int i=0;i<c.num.size();i++)
			if(c.num[i]>9)
			{
				c.num[i]-=10;
				c.num[i+1]++;
			}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
	bigint operator -(const bigint &n)
	{
		bigint c;
		c.num.resize(num.size());
		for(int i=0;i<num.size();i++)
			c.num[i]+=num[i];
		for(int i=0;i<n.num.size();i++)
			c.num[i]-=n.num[i];
		for(int i=0;i<c.num.size();i++)
			if(c.num[i]<0)
			{
				c.num[i]+=10;
				c.num[i+1]--;
			}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
	bigint operator *(const bigint &n)
	{
		bigint c;
		c.num.resize(num.size()+n.num.size()+2);
		for(int i=0;i<num.size();i++)
			for(int j=0;j<n.num.size();j++)
				c.num[i+j]+=num[i]*n.num[j];
		for(int i=0;i<c.num.size();i++)
			if(c.num[i]>9)
			{
				c.num[i+1]+=c.num[i]/10;;
				c.num[i]%=10;
			}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
	bigint operator *(const int &n)
	{
		bigint c;
		c.num.resize(num.size()+30);
		for(int i=0;i<num.size();i++)
			c.num[i]=n*num[i];
		for(int i=0;i<c.num.size();i++)
			if(c.num[i]>9)
			{
				c.num[i+1]+=c.num[i]/10;
				c.num[i]%=10;
			}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
	bigint operator /(const int &n)
	{
		bigint c;
		int rest=0;
		c.num.resize(num.size());
		for(int i=num.size()-1;i>=0;i--)
		{
			rest=rest*10+num[i];
			c.num[i]=rest/n;
			rest%=n;
		}
		while(!(c.num.empty()||c.num.back()))
			c.num.pop_back();
		return c;
	}
	int operator %(const int &n)
	{
		int c=0;
		for(int i=num.size()-1;i>=0;i--)
			c=(c+num[i])%n;
		return c;
	}
	bool operator <(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return num.size()<n.num.size();
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=n.num[i])
				return num[i]<n.num[i];
		return 0;
	}
	bool operator >(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return num.size()>n.num.size();
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=n.num[i])
				return num[i]>n.num[i];
		return 0;
	}
	bool operator ==(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return 0;
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=n.num[i])
				return 0;
		return 1;
	}
};
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	bigint n,m,one;
	bigint left,right,mid;

	one.ament("1");
	cin>>k;
	while(k--)
	for(;;)
	{
		n.read();
		left.ament("1");right=n;
		while(left+one<right)
		{
			mid=(left+right)/2;
			if(mid*mid<n)left=mid;
			else right=mid;
		}
		right.write();
	}
	 
	return 0;
}
