#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int a[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int max1,max2,ans=0;

	cin>>n;
	for(i=1;i<n;i++)for(j=i+1;j<=n;j++)
		cin>>a[i][j],a[j][i]=a[i][j];
	for(i=1;i<=n;i++)
	{
		max1=max(a[i][1],a[i][2]);
		max2=min(a[i][1],a[i][2]);
		for(j=3;j<=n;j++)
			if(a[i][j]>max2)if(a[i][j]>max1)max2=max1,max1=a[i][j];else max2=a[i][j];
		ans=max(ans,max2);
	}
	cout<<"1\n"<<ans;

	return 0;
}