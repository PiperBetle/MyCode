#include<iostream>
#include<cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define abs(a) (((a)>0)?(a):-(a))
#define int long long
using namespace std;
struct segment
{
	int left,right;
};
segment a[100007],f[100007];//到达第i行左右端点的最小值 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i].left>>a[i].right;
	f[1].left=a[1].right+a[1].right-a[1].left-1;
	f[1].right=a[1].right-1;
	for(i=2;i<=n;i++)
	{
		f[i].left=min(f[i-1].left+abs(a[i-1].left-a[i].right),f[i-1].right+abs(a[i-1].right-a[i].right))+a[i].right-a[i].left+1;
		f[i].right=min(f[i-1].left+abs(a[i-1].left-a[i].left),f[i-1].right+abs(a[i-1].right-a[i].left))+a[i].right-a[i].left+1;
	}
	cout<<min(f[n].left-a[n].left,f[n].right-a[n].right)+n;
	
	return 0;
}
