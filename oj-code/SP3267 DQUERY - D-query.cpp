#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
int a[1000007],b[1000007],ans[1000007],cnt[1000007];
struct ask
{
	int l,r,ID;
	bool operator<(const ask &n){return b[l]==b[n.l]?r<n.r:b[l]<b[n.l];}
}q[1000007];
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=(w<<1)+(w<<3)+(c^48);
	return w;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m,t;

	int len=sqrt(n),num=ceil(1.*n/len);
	for(i=1;i<=num;i++)for(j=(i-1)*len+1;j<=i*len;j++)b[j]=i;
	for(i=1;i<=n;i++)a[i]=read();
	m=read();
	for(i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].ID=i;
	std::sort(q+1,q+1+m);
	int l=1,r=0,now=0;
	for(i=1;i<=m;i++)
	{
		while(l<q[i].l)now-=!--cnt[a[l++]];
		while(l>q[i].l)now+=!cnt[a[--l]]++;
		while(r<q[i].r)now+=!cnt[a[++r]]++;
		while(r>q[i].r)now-=!--cnt[a[r--]];
		ans[q[i].ID]=now;
	}
	for(i=1;i<=m;i++)cout<<ans[i]<<'\n';

	return 0;
}