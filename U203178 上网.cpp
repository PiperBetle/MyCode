#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct play{int l,r,w;bool operator<(const play &n){return l>n.l;}}a[10000007];
int sum[10000007],len,f[10000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,now=1;

	cin>>n>>m;
	for(i=1;i<=n;i++)for(cin>>k;k>=1;k--)
		cin>>a[++len].l>>a[len].r>>a[len].w,sum[a[len].l]++;
	std::sort(a+1,a+1+(n=len));
	for(now=1,i=m;i>=1;i--)for(f[i]=f[i+1],j=1;j<=sum[i];j++,now++)
		f[i]=max(f[i],f[a[now].r+1]+a[now].w);
	cout<<f[1];

	return 0;
}