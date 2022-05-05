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
bigint n,m,ans;
bigint result,sum;
bool b[17];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	ans.ament("1");
	n.read();
	cin>>k;
	n.rest_k(k);
	result=n;
	for(i=1;i<=k;i++)
	{
		if((n*result).num[i-1]==n.num[i-1])
			continue;
		sum=result;
		int cnt=1;
		while((n*result).num[i-1]!=n.num[i-1])
		{
			result=sum*result;
			result.rest_k(k);
			cnt++;
			if(cnt>10)
			{
				puts("-1");
				return 0;
			}
		}
		ans=ans*cnt;
	}
	ans.write();
	
	return 0;
}