#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct tree
{
	int data,size,dis,???;
	tree *l,*r;
	tree(){data=dis=???=0;size=1;l=r=nullptr;}
	bool operator<(const tree &n)const{return this->data<n.data;}
	bool flag()
	{
		if(l==nullptr&&r!=nullptr)return 1;
		if(l!=nullptr&&r!=nullptr&&l->dis<r->dis)return 1;
		return 0;
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
int a[1000007],b[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	int x,y,l=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],a[i]-=i;
	for(i=1;i<=n;i++)
	{
		root[++l]=new tree;root[l]->data=a[i];
		while(l>1&&root[l-1]->data>root[l]->data)
		{
			root[l-1]=merge(root[l-1],root[l]);
			root[l-1]->size+=root[l]->size;
			while(root[l-1]->size>(root[l-1]->r->???-root[l-1]->l->???+3>>1))
				root[l-1]->size--,root[l-1]=merge(root[l-1]->l,root[l-1]->r);
		}
	}
	for(i=1;i<=l;i++)for(j=root[i]->l->???;j<=root[i]->r->???;j++)ans+=abs(a[j]-root[i]->data);
	cout<<ans<<'\n';
	for(i=1;i<=l;i++)for(j=root[i]->l->???;j<=root[i]->r->???;j++)cout<<root[i]->data+j<<' ';

	return 0;
}