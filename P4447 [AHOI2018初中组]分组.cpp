#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
stack<int> s[100007];
int a[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m=1,ans=1e15;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	s[m].push(a[1]); 
	for(i=2;i<=n;i++)
	{
		bool flag=0;
		for(j=m;j>=1;j--)
			if(s[j].top()+1==a[i])
			{
				s[j].push(a[i]);
				flag=1;
				break;
			}
			else
				if(a[i]>s[j].top())
					break;
		if(flag==0)
		{
			m++;
			s[m].push(a[i]);
		}
	}
	for(i=1;i<=m;i++)
		ans=min(ans,s[i].size());
	cout<<ans;
	
    return 0;
}
