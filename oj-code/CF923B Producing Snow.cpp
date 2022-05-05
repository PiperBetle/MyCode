#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int v[100007],rest[100007],sum[100007],d[100007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,p,t,cnt=0;
	cin>>n;
	for(i=1;i<=n;i++)cin>>v[i];
	for(i=1;i<=n;i++)cin>>t,sum[i]=sum[i-1]+t;
	for(i=1;i<=n;i++)
		p=std::lower_bound(sum+i,sum+1+n,sum[i-1]+v[i])-sum,
		d[p]++,cnt+=d[i],
		rest[p]+=v[i]+sum[i-1]-sum[p-1],
		cout<<(sum[i]-sum[i-1])*(i-cnt)+rest[i]<<' ';
	
	return 0;
}