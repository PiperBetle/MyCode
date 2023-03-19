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
	bigint()
	{
		num.clear();
	}
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
string s;
bigint find(int x,int y)
{
	string str="";
	for(;x<=y;x++)
		str+=s[x];
	bigint ans;
	ans.ament(str);
	return ans;
}
bigint f[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<107;i++)
		for(j=0;j<107;j++)
			f[i][j].ament("0");
	cin>>n>>t>>s;
	for(i=0;i<n;i++)
		f[0][i]=find(0,i);
	for(i=1;i<=t;i++)
		for(j=1;j<=n;j++)
			for(k=j;k>=i;k--)
			{
				if(f[i-1][k-1]*find(k,j)>f[i][j])
					f[i][j]=f[i-1][k-1]*find(k,j);
			}
	f[t][n-1].write();
	
	return 0;
}