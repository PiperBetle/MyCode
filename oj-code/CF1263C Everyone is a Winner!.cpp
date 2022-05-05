#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
std::vector<int>a;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,T;
	cin>>T;
	while(T--)
	{
		a.clear();a.emplace_back(0);
		cin>>n;
		for(i=1;i*i<=n;i++){
			a.emplace_back(i);
			if(i!=n/i)a.emplace_back(n/i);
		}
		cout<<a.size()<<'\n';
		sort(a.begin(),a.end());
		for(auto it:a)cout<<it<<' ';
		cout<<'\n';
	}
	return 0;
}
