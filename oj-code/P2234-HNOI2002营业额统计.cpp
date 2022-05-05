#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define int long long
using namespace std;
set<int> s;
set<int>::iterator p1,p2;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans;
	int left,right,mid;
	
	cin>>n>>ans;
	s.insert(-0x3f3f3f3f3f3f3f3f);
	s.insert(0x3f3f3f3f3f3f3f3f);
	s.insert(ans);
	for(i=2;i<=n;i++)
	{
		cin>>m;
		p2=s.lower_bound(m);
		p1=p2;p1--;
		ans+=min(m-*p1,*p2-m);
		s.insert(m);
	}
	cout<<ans;
	
	return 0;
}