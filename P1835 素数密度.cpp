#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline double max(double x,double y){return x>y?x:y;}
inline double min(double x,double y){return x<y?x:y;}
inline double abs(double x){return x>0?x:-x;}
using namespace std;
int pr[]={0,2,3,5,7,11,13,17,37};
inline int qp(int n,int p,int k,int t=1)
{
	if(p==0)return 1;
	for(;p;p>>=1,n=n*n%k)
		if(p&1)t=t*n%k;
	return t;
}
bool miller_rabin(int n)
{
	if(n==1)return 0;
	int b,k,x=0,y=n-1;
	while(!(y&1))x++,y>>=1;
	for(int i=1;i<=8&&pr[i]<n;i++)
	{
		b=qp(pr[i],y,n);
		for(int j=1;j<=x;j++)
		{
			k=b*b%n;
			if(k==1&&b!=1&&b!=n-1)return 0;
			b=k;
		}
		if(b!=1)return 0;
	}
	return 1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n>>m;
	for(;n<=m;n++)
		ans+=miller_rabin(n);
	cout<<ans;
		
	return 0;
}
