#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct point
{
	char data;int tag;
	std::vector<point*>a;
	point(){data=tag=0;a.clear();}
}*root=new point;
inline void add(const std::string &s)
{
	point *p=root;
	for(int i=0,j,l=s.length();i<l;i++)
	{
		for(j=0;j<p->a.size();j++)
			if(p->a[j]->data==s[i])break;
		if(j<p->a.size()){p=p->a[j];continue;}
		point *t=new point;
		t->data=s[i];
		p->a.emplace_back(t);
		p=t;
	}
	p->tag=1;
}
inline int find(const std::string &s)
{
	point *p=root;
	for(int i=0,j,l=s.length();i<l;i++)
	{
		for(j=0;j<p->a.size();j++)
			if(p->a[j]->data==s[i])break;
		if(j<p->a.size())p=p->a[j];
		else return 0;
	}
	if(p->tag==-1)return -1;
	p->tag=-1;return 1;
}
std::string name;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	cin>>n;
	while(n--)cin>>name,add(name);
	cin>>m;
	while(m--)
	{
		cin>>name;t=find(name);
		if(t==-1)cout<<"REPEAT\n";
		else if(!t)cout<<"WRONG\n";
		else cout<<"OK\n";
	}
	
	return 0;
}