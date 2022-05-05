#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int h[1000007],v[1000007],a[1000007];
stack<int> s;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>h[i]>>v[i];
	for(i=1;i<=n;i++)
	{
		while((!s.empty())&&(h[s.top()]<h[i]))
		{
			a[i]+=v[s.top()];
			s.pop();
		}
		if(!s.empty())a[s.top()]+=v[i];
		s.push(i);
	}
	for(i=1;i<=n;i++)
		t=max(t,a[i]);
	cout<<t;
	
	return 0;
}
