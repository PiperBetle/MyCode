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
struct trie
{
	char data;int tag;
	std::vector<trie*>a;
	trie(){data=tag=0;a.clear();}
}*root=new trie;
inline void add(const std::string &s)
{
	trie *p=root;
	for(int i=0,j,l=s.length();i<l;i++)
	{
		for(j=0;j<p->a.size();j++)
			if(p->a[j]->data==s[i])break;
		if(j<p->a.size()){p=p->a[j];continue;}
		trie *t=new trie;
		t->data=s[i];
		p->a.emplace_back(t);
		p=t;
	}
	p->tag=1;
}
std::string a[1000007];
int f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;

	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],add(a[i]);
	
	return 0;
}