#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int x[10007],y[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;

	cin>>n;
	for(i=1;i<=n;i++)cin>>x[i]>>y[i];
	x[n+1]=x[1];y[n+1]=y[1];
	for(i=1;i<=n;i++)ans+=x[i]*y[i+1]-x[i+1]*y[i];
	cout<<abs(ans/2);

	return 0;
}