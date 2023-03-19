#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
int m;
struct room{int c,w,f[607];room *s1,*s2;room(){s1=s2=nullptr;memset(f,0,sizeof f);}}*root=new room;
void read(room *&now){
	cin>>now->c>>now->w;now->c<<=1;
	if(!now->w)read(now->s1=new room),read(now->s2=new room);
}
void dfs(room *&now){
	if(now->w){for(int i=0;i/5<=now->w&&now->c+i<m;i++)now->f[now->c+i]=i/5;return;}
	dfs(now->s1);dfs(now->s2);
	for(int i=now->c;i<m;i++)for(int j=0;j+now->c<=i;j++)
		now->f[i]=std::max(now->f[i],now->s1->f[j]+now->s2->f[i-now->c-j]);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>m;read(root);dfs(root);cout<<root->f[m-1];
	return 0;
}