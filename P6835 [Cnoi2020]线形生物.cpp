#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
#define MOD 998244353
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
std::vector<int>s[1000007];
int f[1000007],sum[1000007];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	read();int n=read(),m=read();
	for(int i=1,u,v;i<=m;i++)u=read(),v=read(),s[u].emplace_back(v);
	for(int x=1;x<=n;x++){
		f[x]=s[x].size()+1;
		for(int y:s[x])
			f[x]=((f[x]+sum[x-1]-sum[y-1])%MOD+MOD)%MOD;
		sum[x]=(sum[x-1]+f[x])%MOD;
	}
	printf("%lld",sum[n]);
	return 0;
}