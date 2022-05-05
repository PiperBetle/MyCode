#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x<y?y:x;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return 0<x?x:-x;}
bool f[1007][1007];
int a[57];
inline bool check(int x,int y,int z)
{
	if(x+y>z&&x+z>y&&y+z>x)return 1;
	return 0;
}
inline double calc(double x,double y,double z)
{
	double p=(x+y+z)/2.0;
	return sqrt(p*(p-x)*(p-y)*(p-z));
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int sum=0;
	double ans=-1;
	
	cin>>n;f[0][0]=1;
	for(i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	for(k=1;k<=n;k++)for(i=sum>>1;i>=0;i--)for(j=sum>>1;j>=0;j--)
		f[i][j]|=(i>=a[k]&&f[i-a[k]][j])||(j>=a[k]&&f[i][j-a[k]]);
	for(i=sum>>1;i>0;i--)for(j=sum>>1;j>0;j--)
		if(check(i,j,sum-i-j)&&f[i][j])ans=max(ans,calc(i,j,sum-i-j));
	if(ans<0)cout<<-1;else cout<<(int)(ans*100);
	
	return 0;
}