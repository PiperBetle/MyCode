#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	cin>>n>>k;
	int l=1,r,ans=n*k;
	while(l<=n)
	{
		r=k/l?min(n,k/(k/l)):n;
		ans-=(r-l+1)*(k/l)*(r+l)>>1;
		l=r+1;
	}
	cout<<ans;

	return 0;
}