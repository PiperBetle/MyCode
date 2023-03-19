#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
bool b[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int cnt=0,ans=1;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(!b[t])b[t]=1,cnt++;
		if(cnt==k)cnt=0,memset(b,0,sizeof b),ans++;
	}
	cout<<ans;

	return 0;
}

