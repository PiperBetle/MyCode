#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
using namespace std;
int a[100007];
int find(int left,int right)
{
	if(left>right)return 0;
	if(left==right)return a[left]>0;
	int minn=0x3f3f3f3f3f3f3f3f,p=left;
	for(int i=left;i<=right;i++)
		minn=min(a[i],minn);
	int cnt=minn;
	for(int i=left;i<=right;i++)
	{
		a[i]-=minn;
		if(!a[i])
		{
			cnt+=find(p,i-1);
			p=i+1;
		}
	}
	if(a[right]!=0)
		cnt+=find(p,right);
	for(int i=left;i<=right;i++)
		a[i]+=minn;
	return min(right-left+1,cnt);
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	cout<<find(1,n)<<'\n';
	
	return 0;
}