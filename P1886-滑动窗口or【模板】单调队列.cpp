#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1000007];
deque<int> q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,p;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	p=1;
	for(i=1;i<=n;i++)
	{
		while(!q.empty()&&q.back()>=a[i])
			q.pop_back();
		q.push_back(a[i]);
		if(i-p>=k&&a[p]==q.front())
		{
			p++;
			q.pop_front();
		}
		if(i-p>=k&&a[p]!=q.front())
			p++;
		if(i>=k)
			cout<<q.front()<<" ";
	}
	cout<<'\n';
	
	q.clear();
	p=1;
	for(i=1;i<=n;i++)
	{
		while(!q.empty()&&q.back()<=a[i])
			q.pop_back();
		q.push_back(a[i]);
		if(i-p>=k&&a[p]==q.front())
		{
			p++;
			q.pop_front();
		}
		if(i-p>=k&&a[p]!=q.front())
			p++;
		if(i>=k)
			cout<<q.front()<<" ";
	}
	
    return 0;
}
