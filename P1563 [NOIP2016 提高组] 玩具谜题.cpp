#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define int long long
using namespace std;
struct people
{
	int direction;
	string occupation;
};
people a[1000007];
signed main()
{
//	freopen("toy.in","r",stdin);
//	freopen("toy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i].direction>>a[i].occupation;
		if(a[i].direction==0)a[i].direction=-1;
	}
	int p=1;
	while(m--)
	{
		cin>>x>>y;
		if(x==0)x=-1;
		p=p-a[p].direction*x*y;
		if(p<1)p+=n;
		if(p>n)p-=n;
	}
	cout<<a[p].occupation;
	
	return 0;
}
