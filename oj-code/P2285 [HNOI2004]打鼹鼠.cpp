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
struct mice{int x,y,time;int operator-(const mice &n)const{return abs(x-n.x)+abs(y-n.y);}}a[10007];
int f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n>>m;
	for(i=1;i<=m;i++)cin>>a[i].time>>a[i].x>>a[i].y,f[i]=1;
	for(i=1;i<=m;i++)for(j=1;j<i;j++)
		if(a[i]-a[j]<=a[i].time-a[j].time)
			f[i]=max(f[i],f[j]+1);
	for(i=1;i<=m;i++)ans=max(ans,f[i]);
	cout<<ans;

	return 0;
}