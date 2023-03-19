#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
priority_queue<int> q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	int a,b;
	
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		q.push(t);
	}
	for(i=1;;i++)
	{
		t=q.top();
		q.pop();
		t-=b;
		q.push(t);
		if(q.top()-i*a<=0)
		{
			cout<<i<<'\n';
			return 0;
		}
	}
	
    return 0;
}
