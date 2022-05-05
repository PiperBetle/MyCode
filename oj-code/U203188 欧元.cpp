#include<iostream>
#include<cstring>
#include<unordered_map>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[10007],f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;

	memset(f,-0x3f,sizeof f);f[0]=0;
	cin>>n>>t;
	for(i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1];
	for(i=1;i<=n;i++)for(j=0;j<=i;j++)f[i]=max(f[i],f[j]+(a[i]-a[j])*i-t);
	cout<<f[n];

	return 0;
}