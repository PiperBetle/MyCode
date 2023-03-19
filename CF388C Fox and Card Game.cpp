#include<iostream>
#include<algorithm>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
priority_queue<int>q;
using std::cin;using std::cout;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m,t,ans1=0,ans2=0;bool now=true;
	cin>>m;
	while(m--)
	{
		cin>>n;
		for(i=(n>>1);i--;)cin>>t,ans1+=t;
		if(n&1)cin>>t,q.push(t);
		for(i=(n>>1);i--;)cin>>t,ans2+=t;
	}
	while(!q.empty())
		now?ans1+=q.top():ans2+=q.top(),
		q.pop(),
		now=!now;
	cout<<ans1<<' '<<ans2;
	return 0;
}