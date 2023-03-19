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
int a[300007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,p;
	
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	i=0;j=1;k=0;
	while(i<=n&&j<=n&&k<=n)
	{
		if(a[(i+k)%n]==a[(j+k)%n]){k++;continue;}
		if(a[(i+k)%n]>a[(j+k)%n])i+=k+1;
		else j+=k+1;
		k=0;if(i==j)j++;
	}
	p=min(i,j);
	for(i=0;i<n;i++)cout<<a[(i+p)%n]<<' ';
	
	return 0;
}
