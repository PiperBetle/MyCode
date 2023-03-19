#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>n;
		if(n==3)cout<<"Case "<<i<<": 2 3\n";
		else cout<<"Case "<<i<<": "<<(n>>1)<<' '<<(n-(n&1))<<'\n';
	}

	return 0;
}