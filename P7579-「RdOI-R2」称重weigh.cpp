#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
char weight(vector<int> x,vector<int> y)
{
	cout<<"1 "<<x.size();
	int i;
	for(i=x.size()-1;i>=0;i--)
		cout<<" "<<x[i];
	cout<<" "<<y.size();
	for(i=y.size()-1;i>=0;i--)
		cout<<" "<<y[i];
	cout<<endl;
	char c;
	cin>>c;
	return c;
}
void calc(vector<int> a)
{
	int n=a.size();
	if(n==2)
		return a;
	if(n==3)
	{
		vector<int> x,y;
		x.push_back(a[0]);
		y.push_back(a[1]);
		char flag=weight(x,y);
		if(flag=='=')
		{
			x.push_back(a[1]);
			return x;
		}
		else if(flag=='>')
		{
			y.push_back(a[2]);
			return y;
		}
		else if(flag=='<')
		{
			x.push_back(a[2]);
			return x;
		}
	}
	if(n==4)
	{
		vector<int> x,y;
		x.push_back(a[0]);
		y.push_back(a[1]);
		char flag=weight(x,y);
		if(flag=='=')
		{
			vector<int> z;
			z.push_back(a[2]);
			flag=weight(y,z);
			if(z=='>')
			{
				z.push_back(a[3]);
				return z;
			}
			else if(z=='<')
			{
				x.push_back(a[1]);
				return x;
			}
		}
		else
		{
			
		}
	}
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	vector<int> a;
	
	cin>>n;
	a.resize(n);
	a=calc(a);

	return 0;
}