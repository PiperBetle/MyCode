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
struct point{int x,y;int operator-(const point &n){return abs(x-n.x)+abs(y-n.y);}}a[100007],b[100007];
int f[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int x,y,a,b,ans=-1;
	
	memset(f,0x3f,sizeof f);
	cin>>n>>m>>a>>b;
	for(i=1;i<=a;i++)cin>>::a[i].x>>::a[i].y;
	for(i=1;i<=b;i++)cin>>::b[i].x>>::b[i].y;
	for(i=1;i<=b;i++)for(j=1;j<=a;j++)
		f[i]=min(f[i],::a[j]-::b[i]);
	for(i=1;i<=b;i++)cout<<f[i]<<'\n';
	
	return 0;
}