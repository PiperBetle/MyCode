#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
char ibuf[1000007],*p1=ibuf,*p2=ibuf;
#define getchar() (p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1000007,stdin),p1==p2)?EOF:*p1++)
inline int read(){
	int w=0,y=1,c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')y=-1;
	for(;isdigit(c);c=getchar())w=w*10+(c^48);
	return w*y;
}
int a[1000007],bl[1000007],ans[1000007],l,r,now,vis[1000007];
struct ask{int l,r,id;bool operator<(const ask &t){return bl[l]==bl[t.l]?r<t.r:bl[l]<bl[t.l];}}q[1000007];
inline void del(int x){vis[a[x]]--;if(!vis[a[x]])now--;}
inline void add(int x){if(!vis[a[x]])now++;vis[a[x]]++;}
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
	int n=read(),m=read(),size=__builtin_sqrt(n),num=0;
	for(int i=1;i<=n;i++){a[i]=read();if(i%size==1)num++;bl[i]=num;}
	for(int i=1;i<=m;i++)q[i].l=read(),q[i].r=read(),q[i].id=i;
	std::sort(q+1,q+1+m);
	for(int i=1;i<=m;i++){
		while(l<q[i].l)del(l++);
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(r>q[i].r)del(r--);
		if(now==q[i].r-q[i].l+1)ans[q[i].id]=1;
	}
	for(int i=1;i<=m;i++)cout<<(ans[i]?"Yes\n":"No\n");
	return 0;
}