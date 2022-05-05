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
	void read()
	{
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(int i=0;i<num.size();i++)
			num[i]=s[i]-48;
	}
	void write()
	{
		cout<<num[num.size()-1];
		for(int i=num.size()-2;i>=0;i--)
			cout<<num[i];
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
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	bigint n,a,b,a0,d;
	bigint ans;
	
	// n,a,b=map(float,input().split())
	// a0=a*a*b/2.0
	// d=b*b*b/2.0
	// ans=n*a0+n*(n-1)*d/2.0
	// print("%.6f"%ans)
	n.read();
	a.read();
	b.read();
	a0=a*a*b;
	d=b*b*b;
	ans=(n*a0)+(n*n-n)*d/2;
	k=ans.num[0];
	ans=ans/2;
	ans.write();
	if(k&1)
		cout<<".500000\n";
	else
		cout<<".000000\n";
	
	return 0;
}