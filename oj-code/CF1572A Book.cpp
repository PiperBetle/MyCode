#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using std::cin;using std::cout;
std::set<int>bbt;
std::vector<int>s[200007];
int in[200007];
signed main()
{
//	freopen("book.in","r",stdin);
//	freopen("book.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,T=1,u;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(i=1;i<=n;i++)s[i].clear();
		for(i=1;i<=n;i++)
			for(cin>>in[i],j=1;j<=in[i];j++)
				cin>>u,s[u].emplace_back(i);
		int ans=1,pre=0,cnt=0;
		for(i=1;i<=n;i++)if(!in[i])bbt.insert(i);
		while(bbt.size())
		{
			auto p=bbt.upper_bound(pre);
			auto last=bbt.end();last--;
			if(pre>*last)p=bbt.lower_bound(0),ans++;
			bbt.erase(u=*p);
			cnt++;
			for(auto it:s[u])if(!--in[it])bbt.insert(it);
			pre=u;
		}
		if(cnt!=n)cout<<"-1\n";else cout<<ans<<'\n';
	}
	return 0;
}