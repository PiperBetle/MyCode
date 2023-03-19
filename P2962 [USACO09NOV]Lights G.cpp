#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<unordered_map>
#define int long long
std::unordered_map<int,int>f;
using std::cin;using std::cout;
int a[41];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,n,m,u,v,ans=0x3f3f3f3f3f3f3f3f;
	cin>>n>>m;
	for(i=a[0]=1;i<n;i++)a[i]=a[i-1]<<1;
	for(i=0;i<m;i++)cin>>u>>v,u--,v--,a[u]|=(1ll<<v),a[v]|=(1ll<<u);
	for(i=0;i<(1ll<<(n>>1));i++){
		int t=0,cnt=0;
		for(j=0;j<(n>>1);j++)if((i>>j)&1)t^=a[j],cnt++;
		if(!f.count(t))f[t]=cnt;else f[t]=std::min(f[t],cnt);
	}
	for(i=0;i<(1ll<<(n-(n>>1)));i++){
		int t=0,cnt=0;
		for(j=0;j<(n-(n>>1));j++)if((i>>j)&1)t^=a[(n>>1)+j],cnt++;
		if(f.count(((1ll<<n)-1)^t))ans=std::min(ans,cnt+f[(((1ll<<n)-1)^t)]);
	}
	cout<<ans;
	return 0;
}