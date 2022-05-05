#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int f[1007][1007][2];
struct work{int x,t;bool operator<(const work&n)const{return x<n.x;}}a[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,T;
	int h,b,ans=0x3f3f3f3f;
	
	cin>>n>>h>>b;
	for(i=1;i<=n;i++)cin>>a[i].x>>a[i].t;
	std::sort(a+1,a+1+n);
	memset(f,0x3f,sizeof f);
	f[1][n][0]=max(a[1].x,a[1].t);
	f[1][n][1]=max(a[n].x,a[n].t);
	for(i=1;i<=n;i++)for(j=n;j>=1;j--)
	{
		f[i][j][0]=min(f[i][j][0],max(a[i].t,f[i-1][j][0]+a[i].x-a[i-1].x));
		f[i][j][0]=min(f[i][j][0],max(a[i].t,f[i][j+1][1]+a[j+1].x-a[i].x));
		f[i][j][1]=min(f[i][j][1],max(a[j].t,f[i][j+1][1]+a[j+1].x-a[j].x));
		f[i][j][1]=min(f[i][j][1],max(a[j].t,f[i-1][j][0]+a[j].x-a[i-1].x));
	}
	for(i=1;i<=n;i++)ans=min(ans,min(f[i][i][0],f[i][i][1])+abs(a[i].x-b));
	cout<<ans;
	
	return 0;
}
