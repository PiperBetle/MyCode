
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<string>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct bigint
{
	std::vector<int>num;
	bigint(){num.clear();}
	void write(){for(int i=num.size()-1;i>=0;i--)cout<<num[i];cout<<'\n';}
	bigint operator +(const bigint &n)const
	{
		bigint c;
		c.num.resize(max(num.size(),n.num.size())+1);
		for(int i=0;i<num.size();i++)c.num[i]+=num[i];
		for(int i=0;i<n.num.size();i++)c.num[i]+=n.num[i];
		for(int i=0;i<c.num.size();i++)if(c.num[i]>9){c.num[i]-=10;c.num[i+1]++;}
		while(!(c.num.empty()||c.num.back()))c.num.pop_back();
		return c;
	}
	bigint operator *(const int &n)const
	{
		bigint c;
		c.num.resize(num.size()+30);
		for(int i=0;i<num.size();i++)c.num[i]=n*num[i];
		for(int i=0;i<c.num.size();i++)if(c.num[i]>9){c.num[i+1]+=c.num[i]/10;c.num[i]%=10;}
		while(!(c.num.empty()||c.num.back()))c.num.pop_back();
		return c;
	}
}f[107][107];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<=100;i++)for(j=0;j<=100;j++)
		if(j==0||j>i)f[i][j].num.emplace_back(0);
		else if(i==j||j==1)f[i][j].num.emplace_back(1);
		else f[i][j]=f[i-1][j]*j+f[i-1][j-1];
	while(cin>>n>>m)f[n][m].write();
	
	return 0;
}