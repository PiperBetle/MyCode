#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct sth{int left,right;bool operator<(const sth &n){return right<n.right;}}a[1000007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].left>>a[i].right;
	std::sort(a+1,a+1+n);
	int st=-1;
	for(i=1;i<=n;i++)
		if(a[i].left>=st){ans++;st=a[i].right;}
	cout<<ans;
	
	return 0;
}