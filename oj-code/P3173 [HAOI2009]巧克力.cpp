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
int a[1000007],b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i=1,j=1,k;
	int n,m,ans=0;
	
	cin>>n>>m;n--;m--;
	for(k=1;k<=n;k++)cin>>a[k];
	std::sort(a+1,a+1+n,std::greater<int>());
	for(k=1;k<=m;k++)cin>>b[k];
	std::sort(b+1,b+1+m,std::greater<int>());
	while(i<=n&&j<=m)
		if(a[i]>b[j])ans+=a[i++]*j;
		else ans+=b[j++]*i;
	while(i<=n)ans+=a[i++]*j;
	while(j<=m)ans+=b[j++]*i;
	cout<<ans;
	
	return 0;
}
