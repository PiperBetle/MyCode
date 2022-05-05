#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
std::string s;
using std::cin;using std::cout;
template<typename any>inline any min(any x,any y){return x<y?x:y;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>s;
		int sum=std::count(s.begin(),s.end(),'1'),ans=0x3f3f3f3f,cnt;
		for(i=0;i<m;i++)for(cnt=0,j=i;j<n;j+=m)
			cnt=min(s[j]=='1'?cnt-1:cnt+1,0),
			ans=min(ans,sum+cnt);
		cout<<ans<<'\n';
	}
	return 0;
}