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
struct point{int x,y;bool operator<(const point &n){if(x==n.x)return y<n.y;return x<n.x;}}a[5000007];
bool b[5000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,maxn=-1;

	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	std::sort(a+1,a+1+n);
	for(i=n;i>=1;i--)
		if(maxn<a[i].y)b[i]=1,maxn=a[i].y;
	for(i=1;i<n;i++)if(b[i])cout<<'('<<a[i].x<<','<<a[i].y<<"),";
	cout<<'('<<a[n].x<<','<<a[n].y<<')';

	return 0;
}