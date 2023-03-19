#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct number
{
	int left,right;
	int data;
};
number a[1000007];
stack<int> s;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	while(cin>>n)
	{
		if(n==0)
			return 0;
		for(i=1;i<=n;i++)
		// a[0].data=a[n+1].data=1e9;
			cin>>a[i].data;
		for(i=1;i<=n;i++)
		{
			while(!s.empty()&&a[s.top()].data>=a[i].data)s.pop();
			// if(s.empty())a[i].left=1;
			if(s.empty())a[i].left=0;
			else a[i].left=s.top();
			s.push(i);
		}
		while(!s.empty())
			s.pop();

		for(i=n;i>=1;i--)
		{
			while(!s.empty()&&a[s.top()].data>=a[i].data)s.pop();
			// if(s.empty())a[i].right=n;
			if(s.empty())a[i].right=n+1;
			else a[i].right=s.top();
			s.push(i);
		}
		while(!s.empty())
			s.pop();
		
		int ans=0;
		// cout<<"  ";
		for(i=1;i<=n;i++)
		{
			// cout<<a[i].left<<" ";
			ans=max(ans,a[i].data*(i-a[i].left));
			ans=max(ans,a[i].data*(a[i].right-i));
		}
		// cout<<'\n';
		cout<<ans<<'\n';
	}
	
	return 0;
}