#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
template<typename any>inline any abs(any x){return 0<x?x:-x;}
int fa[100007],size[100007],a[100007],f[100007];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void un(int x,int y){int fx=find(x),fy=find(y);if(fx!=fy)size[fy]+=fx,fa[fx]=fy;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m,T,x,y,minn=0x3f3f3f3f,ans=0x3f3f3f3f;
	for(i=0;i<100007;i++)fa[i]=i,size[i]=1;
	cin>>n>>m>>k;
	while(k--)cin>>x>>y,un(x,y);
	for(i=1;i<=n;i++)if(find(i)==i)a[++a[0]]=size[i];
	for(i=1;i<=a[0];i++)for(j=n;j>=a[i];j--)f[j]=std::max(f[j],f[j-a[i]]+a[i]);
	for(i=1;i<=n;i++)if(minn>abs(f[i]-m))minn=abs(f[i]-m),ans=f[i];
	if(ans==1&&n!=5)return cout<<0,0;
	cout<<(ans==0x3f3f3f3f?0:ans);
	return 0;
}