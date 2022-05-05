#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
auto MAX(auto x,auto y){return x>y?x:y;}
auto MIN(auto x,auto y){return x<y?x:y;}
int n,m,q;
int a[100007],max_tree[100007],min_tree[100007];
int lowbit(int _x)
{
	return _x&(-_x);
}
void build(int _x,int _k)
{
	for(;_x<=n;_x+=lowbit(_x))
	{
		max_tree[_x]=MAX(max_tree[_x],_k);
		min_tree[_x]=MIN(min_tree[_x],_k);
	}
}
int max_find(int _x,int _y)
{
	if(_x<_y)
		if(_x<_y-lowbit(_y))
			return MAX(max_tree[_y],max_find(_x,_y-lowbit(_y)));
		else
			return MAX(a[_y],max_find(_x,_y-1));
	return a[_x];
}
int min_find(int _x,int _y)
{
	if(_x<_y)
		if(_x<_y-lowbit(_y))
			return MIN(min_tree[_y],min_find(_x,_y-lowbit(_y)));
		else
			return MIN(a[_y],min_find(_x,_y-1));
	return a[_x];
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	memset(min_tree,0x3f,sizeof min_tree);
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		build(i,a[i]);
	}
	while(q--)
	{
		cin>>i>>j;
		cout<<max_find(i,j)-min_find(i,j)<<'\n';
	}
	
	return 0;
}
