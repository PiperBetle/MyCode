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
	inline void ament(string s)
	{
		reverse(s.begin(),s.end());
		num.resize(s.size());
		for(int i=0;i<num.size();i++)
			num[i]=s[i]-48;
	}
	inline void read()
	{
		string s;
		cin>>s;
		ament(s);
	}
	inline void write()
	{
		cout<<num[num.size()-1];
		for(int i=num.size()-2;i>=0;i--)
			cout<<num[i];
		cout<<'\n';
	}
	inline void rest_k(const int &k)
	{
		for(;;)
			if(num.size()>k)
				num.pop_back();
			else
				return;
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
	bool operator <(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return num.size()<n.num.size();
		for(int i=num.size();i>=0;i--)
			if(num[i]!=n.num[i])
				return num[i]<n.num[i];
		return 0;
	}
	bool operator >(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return num.size()>n.num.size();
		for(int i=num.size();i>=0;i--)
			if(num[i]!=n.num[i])
				return num[i]>n.num[i];
		return 0;
	}
};
bigint ans1,ans2;
bigint per(int m,int n)
{
	bigint ans;
	ans.ament("1");
	for(int i=n-m+1;i<=n;i++)
		ans=ans*i;
	if(n<m)
		ans.ament("0");
	return ans;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n>>m;
	if(n==0&&m==0)
	{
		puts("0");
		return 0;
	}
	ans1.ament("1");
	ans2.ament("2");
	ans2=ans2*n+ans2;
	for(i=1;i<=n;i++)
	{
		ans1=ans1*i;
		ans2=ans2*i;
	} 
	ans1=ans1*per(2,n+1);
	ans1=ans1*per(m,n+3);
	ans2=ans2*m;
	ans2=ans2*per(m-1,n+2);
	ans1=ans1+ans2;
	ans1.write();
	
	return 0;
}