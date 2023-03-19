#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct bigint
{
	std::vector<int>num;
	void ament(std::string s)
	{
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
		cout<<'\n';
	}
	bigint operator+(const bigint &n)
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
	bigint operator*(const int &n)
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
	bigint operator/(const int &n)
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
	bool operator <(const bigint &n)
	{
		if(num.size()!=n.num.size())
			return num.size()<n.num.size();
		for(int i=num.size()-1;i>=0;i--)
			if(num[i]!=n.num[i])
				return num[i]<n.num[i];
		return 0;
	}
};
bigint ans,mul,temp;
struct minister{int l,r;bool operator<(const minister &n)const{return l*r<n.l*n.r;}}a[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y;
	
	cin>>n;
	for(i=0;i<=n;i++)cin>>a[i].l>>a[i].r;
	std::sort(a+1,a+1+n);
	ans.ament("0");mul.ament(std::to_string(a[0].l));
	for(i=1;i<=n;i++)
	{
		temp=mul/a[i].r;
		if(ans<temp)ans=temp;
		mul=mul*a[i].l;
	}
	ans.write();

    return 0;
}