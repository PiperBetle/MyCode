#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
#define int long long
constexpr int MOD=1000000007;
int fac=1,n,a[100007],b[100007],pos[100007],f[100007];
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
struct BIT{
	int data[100007];
	void add(int x,int k=1){for(;x<=n;x+=x&-x){data[x]+=k;if(data[x]>=MOD)data[x]-=MOD;}}
	int sum(int x,int k=0){for(;x;x-=x&-x)k+=data[x];return k%MOD;}
	int query(int l,int r){return sum(r)-sum(l-1);}
}tree;
signed main(){
//	freopen("shuffle.in","r",stdin);
//	freopen("shuffle.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;for(int i=2;i<=n;i++)fac=fac*i%MOD;
	for(int i=1,x,y;i<=n;i++)cin>>x>>y,a[x]=y,pos[y]=i;
	for(int i=n;i>=1;i--)b[i]=tree.query(a[i],n),tree.add(a[i]),b[i]=qp(b[i],MOD-2);
	std::fill_n(tree.data,n+1,0);tree.add(1,qp(n,MOD-2));
	for(int i=1;i<=n;i++)
		if(!b[i])f[pos[a[i]]]=tree.sum(a[i])*fac%MOD;
		else tree.add(a[i]+1,tree.sum(a[i])*b[i]%MOD);
	for(int i=1;i<=n;i++)cout<<f[i]<<'\n';
	return 0;
}