#include<iostream>
#include<cstdio>
#include<algorithm>
int n,m,d,dep[500007],p[500007][20];
std::vector<int>s[500007];
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#if ONLINE_JUDGE
	#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
#endif
inline int read(){
	int w=0,c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w;
}
void dfs(int now,int fa){
	dep[now]=dep[fa]+1;p[now][0]=fa;
	for(int i=1;(1<<i)<=dep[now];i++)p[now][i]=p[p[now][i-1]][i-1];
	for(auto it:s[now])if(it!=fa)dfs(it,now);
}
int LCA(int a,int b){
	if(dep[a]>dep[b])std::swap(a,b);
	for(int i=d;i>=0;i--)if(dep[a]<=dep[b]-(1<<i))b=p[b][i];
	if(a==b)return a;
	for(int i=d;i>=0;i--)if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
#define dis(x,y) (dep[x]+dep[y]-(dep[LCA(x,y)]<<1))
int main(){
	n=read(),m=read(),d=std::__lg(n);
	for(int i=1,u,v;i<n;i++)u=read(),v=read(),s[u].emplace_back(v),s[v].emplace_back(u);
	dfs(1,0);while(m--){
		int q1=read(),q2=read(),q3=read(),min=0x3f3f3f3f,pos=0;
		if(int lca=LCA(q1,q2),sum=dep[q1]+dep[q2]-(dep[lca]<<1)+dis(q3,lca);min>sum)min=sum,pos=lca;
		if(int lca=LCA(q1,q3),sum=dep[q1]+dep[q3]-(dep[lca]<<1)+dis(q2,lca);min>sum)min=sum,pos=lca;
		if(int lca=LCA(q2,q3),sum=dep[q2]+dep[q3]-(dep[lca]<<1)+dis(q1,lca);min>sum)min=sum,pos=lca;
		printf("%d %d\n",pos,min);
	}
	return 0;
}