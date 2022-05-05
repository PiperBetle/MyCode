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
	int data,ID,dis;
	tree *l,*r;
	tree(){data=ID=dis=0;l=r=nullptr;}
	bool flag()
	{
		if(l==nullptr&&r!=nullptr)return 1;
		if(l!=nullptr&&r!=nullptr&&l->dis<r->dis)return 1;
		return 0;
	}
	bool operator<(const tree &n)const
	{
		if(this->data==n.data)return this->ID>n.ID;
		return this->data>n.data;
	}
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
int f[1000007],sum[1000007];
bool b[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y,z;
	
	cin>>n>>m;
	for(i=0;i<1000007;i++)f[i]=i;
	for(i=1;i<=n;i++)root[i]=new tree,cin>>root[i]->data,root[i]->ID=i;
	for(i=1;i<=m;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x>>y;
			if(b[x]||b[y])continue;
			int fx=find(x),fy=find(y);
			if(fx==fy)continue;
			if(sum[fx]<sum[fy])t=fx,fx=fy,fy=t;
			f[fy]=fx;
			sum[fx]+=sum[fy];
			root[fx]=merge(root[fx],root[fy]);
		}
		else
		{
			cin>>x;
			if(b[x]){cout<<"-1\n";continue;}
			int fx=find(x);
			cout<<root[fx]->data<<'\n';
			b[root[fx]->ID]=1;
			root[fx]=merge(root[fx]->l,root[fx]->r);
		}
	}

	return 0;
}