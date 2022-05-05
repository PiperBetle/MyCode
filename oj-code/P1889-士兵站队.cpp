#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) ((a)<0?-(a):(a))
using namespace std;
void qs(int left,int right,int a[])
{
	int p1=left,p2=right,mid;
	mid=a[(left+right)/2];
	do
	{
		while(a[p1]<mid)p1++;
		while(a[p2]>mid)p2--;
		if(p1<=p2)swap(a[p1],a[p2]),p1++,p2--;
	}
	while(p1<=p2);
	if(left<p2)qs(left,p2,a);
	if(p1<right)qs(p1,right,a);
}
int x[1000007],y[1000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int fx,fy,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	qs(1,n,x);
	qs(1,n,y);
	for(i=1;i<=n;i++)
		x[i]-=i;
	qs(1,n,x);
	if(n&1)
	{
		fx=x[n/2+1];
		fy=y[n/2+1];
	}
	else
	{
		fx=(x[n/2]+x[n/2+1])/2;
		fy=(y[n/2]+y[n/2+1])/2;
	}
	for(i=1;i<=n;i++)
		ans+=abs(fx-x[i])+abs(fy-y[i]);
	cout<<ans<<'\n';
	
	return 0;
}