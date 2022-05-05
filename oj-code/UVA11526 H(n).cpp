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
int a[1000007],b[1000007],tag[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int l,r,ans;

	for(cin>>T;T;T--)
	{
		cin>>n;
		l=1;ans=0;
		while(l<=n)
		{
			r=n/(n/l);
			ans+=(r-l+1)*(n/l);
			l=r+1;
		}
		cout<<ans<<'\n';
	}

	return 0;
}