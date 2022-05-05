#include<iostream>
#include<cstring>
#include<deque>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct day{int left,right,ID;};
deque<day> q;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	day t;
	int ans=-1;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t.left>>t.right;
		t.ID=i;
		while(!q.empty()&&q.front().left>t.right)
			q.pop_front();
		if(!q.empty())
			ans=max(ans,i-q.front().ID+1);
		while(!q.empty()&&q.back().left<t.left)
		{
			t.ID=q.back().ID;
			q.pop_back();
		}
		q.push_back(t);
	}
	cout<<ans<<'\n';
	
	return 0;
}