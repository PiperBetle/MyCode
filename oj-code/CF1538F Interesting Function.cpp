#include<iostream>
using std::cin;using std::cout;
inline int calc(int x,int res=0){while(x)res+=x,x/=10;return res;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T,n,m;
	cin>>T;while(T--)cin>>n>>m,cout<<calc(m)-calc(n)<<'\n';
	return 0;
}