#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int d[2000007],n,m,p,ans=0;
inline int calc(int n,int k,int sum=0){for(int i=k;i<=n;i+=k)sum+=d[i];return sum%p;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>p;if(n>m)std::swap(n,m);
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j+=i)d[j]++;
	for(int i=1;i<=n;i++)ans=(ans+calc(n,i)*calc(m,i))%p;
	cout<<ans;
	return 0;
}