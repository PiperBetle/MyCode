#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#define int long long
using std::cin;using std::cout;
int a[200007],belong[200007],sum[1007];
std::vector<int>s[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int l,r,x,y,z,type;
	
	cin>>n>>m;
	int size=ceil(sqrt(n)),num=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i%size==1)num++;
		belong[i]=num;
		s[num].emplace_back(a[i]);
		sum[num]+=a[i];
	}
	while(m--)
	{
		cin>>type;
		if(type==1)
		{
			cin>>x>>y>>z;
			if(x>80)
			{
				for(;y<=n;y+=x)sum[belong[i]]+=z,a[i]+=z;
			}
		}
	}
	
	return 0;
}