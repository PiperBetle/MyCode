#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct tree
{
	int data,dis;
	tree *l,*r;
	tree(){data=dis=0;l=r=nullptr;}
	bool flag()
	{
		if(l==nullptr&&r!=nullptr)return 1;
		if(l!=nullptr&&r!=nullptr&&l->dis<r->dis)return 1;
		return 0;
	}
	bool operator<(const tree &n)const{return this->data<n.data;}
};
tree *root[1000007];
tree *merge(tree *x,tree *y)
{
	if(x==nullptr)return y;
	if(y==nullptr)return x;
	if(*x<*y)std::swap(x,y);
	x->r=merge(x->r,y);
	if(x->flag())std::swap(x->l,x->r);
	x->dis=(x->r==nullptr?0:x->r->dis+1);
	return x;
}
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,z;
	
	while(cin>>n)
	{
		for(i=0;i<1000007;i++)f[i]=i;
		for(i=1;i<=n;i++)root[i]=new tree,cin>>root[i]->data;
		cin>>m;
		for(i=1;i<=m;i++)
		{
			cin>>x>>y;
			int fx=find(x),fy=find(y);
			if(fx==fy){cout<<"-1\n";continue;}
			f[fy]=fx;
			root[fx]=merge(root[fx],root[fy]);
			cout<<(root[fx]->data>>=1)<<'\n';
			tree *p=new tree;p->data=root[fx]->data;
			root[fx]=merge(root[fx]->l,root[fx]->r);
			root[fx]=merge(p,root[fx]);
		}
	}

	return 0;
}