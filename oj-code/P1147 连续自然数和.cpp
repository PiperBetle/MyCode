#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define int long long
using namespace std;
inline int sum(int x,int y)
{
	return (x+y)*(y-x+1)/2;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>n;
	int l=1,r=1;
	for(;;)
	{
		if(sum(l,r)==n)
		{
			if(l!=r)cout<<l<<" "<<r<<"\n";
			l++;r++;
		}
		else if(sum(l,r)<n)
		{
			r++;
		}
		else
		{
			l++;
		}
		if(r>n)return 0;
	}
	
	return 0;
}
