#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1000007],d[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int cnt1=0,cnt2=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=n;i++)
	{
		d[i]=a[i]-a[i-1];
		if(d[i]>0)cnt1+=d[i];
		else cnt2-=d[i];
	}
	cout<<max(cnt1,cnt2)<<'\n'<<abs(cnt1-cnt2)+1;
	
	return 0;
}
