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
int ans[10007][2],a[10007],n,m;
bool check(int x)
{
	int sum=0,cnt=0;
	for(int i=n;i>=1;sum+=a[i--])
		if(sum+a[i]>x)sum=0,cnt++;
	return cnt>=m;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k=1;
	int left=0,right=0,mid;

	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i],left=max(left,a[i]),right+=a[i];
	while(left+1<right)
	{
		mid=left+right>>1;
		if(check(mid))left=mid;
		else right=mid;
	}
	ans[1][1]=n;
	int sum=0;
	for(i=n;i>=1;sum+=a[i--])
		if(sum+a[i]>right)sum=0,ans[k][0]=i+1,ans[++k][1]=i;
	ans[k][0]=1;
	for(i=k;i>=1;i--)cout<<ans[i][0]<<' '<<ans[i][1]<<'\n';
	
	return 0;
}