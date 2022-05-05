#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;	
int a[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int x,y,s1=0,s2=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s2+=a[i];
	}
	cin>>x>>y;
	for(i=1;i<=n;i++)
	{
		if(s1>=x&&s2>=x&&s1<=y&&s2<=y)
		{
			cout<<i;
			return 0;
		}
		s1+=a[i];
		s2-=a[i];
	}
	cout<<0;
	
	return 0;
}
