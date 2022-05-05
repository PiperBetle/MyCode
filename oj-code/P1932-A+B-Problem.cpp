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
	bigint operator+(const bigint a,const bigint &b)
	{
		bigint c;
		c.num.resize(max(a.num.size(),b.num.size())+1);
		for(int i=0;i<a.num.size();i++)
			c.num[i]+=a.num[i];
		for(int i=0;i<b.num.size();i++)
			c.num[i]+=b.num[i];
		for(int i=0;i<c.num.size();i++)
			if(c.num[i]>9)
			{
				c.num[i]-=10;
				c.num[i+1]++;
			}
		while(!(c.num.empty||c.num.back()))
			c.num.pop_back();
		return c;
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	bigint n,m;
	
	
	
	return 0;
}