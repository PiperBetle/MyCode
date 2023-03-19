#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#define int long long
using std::cin;using std::cout;
std::unordered_map<int,bool>map;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	
	cin>>T;
	while(T--)
	{
		map.clear();
		cin>>n;
		while(n--){cin>>m;if(!map.count(m)){cout<<m<<' ';map[m]=1;}}
		cout<<'\n';
	}
	
	return 0;
}