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
int n,k,a[1000007];
bool check1(int x,int cnt=0){for(int i=1;i<=n;i++)cnt+=max(0,x-a[i]);return cnt<=k;}
bool check2(int x,int cnt=0){for(int i=1;i<=n;i++)cnt+=max(0,a[i]-x);return cnt<=k;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j;
	int minn,maxn=0,sum=0,arv;
	int left,right,mid;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)cin>>a[i],maxn=max(maxn,a[i]),sum+=a[i];
	arv=sum/n;
	left=1;right=arv;
	while(left+1<right)
	{
		mid=left+right>>1;
		if(check1(mid))left=mid;
		else right=mid;
	}
	minn=right;
	left=arv+(sum%n!=0);right=maxn;
	while(left+1<right)
	{
		mid=left+right>>1;
		if(check2(mid))left=mid;
		else right=mid;
	}
	maxn=right;
	cout<<maxn-minn;

	return 0;
}
