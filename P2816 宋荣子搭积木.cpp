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
int a[10007],b[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(i=1;i<=n;i++)
	{
		if(b[i])continue;
		b[i]=1;ans++;m=1;
		for(j=i+1;j<=n;j++)
			if(!b[j]&&m<=a[j])b[j]=1,m++;
	}
	cout<<ans;

	return 0;
}
