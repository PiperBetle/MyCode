#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin,std::cout;
struct trie_01{
	trie_01 *d[2]={};
	int s=0,v=0;
	auto &operator[](int x){return d[x];}
	trie_01 &push_up(){
		s=v=0;
		if(d[0])s+=d[0]->s,v^=d[0]->v<<1;
		if(d[1])s+=d[1]->s,v^=d[1]->v<<1|(d[1]->s&1);
		s&=1;
		return *this;
	}
	trie_01 &add(){
		std::swap(d[0],d[1]);
		if(d[0])d[0]->add();
		return push_up();
	}
	void insert(int x,int dep){
		if(dep>20){s++;return;}
		if(!d[x&1])d[x&1]=new trie_01;
		d[x&1]->insert(x>>1,dep+1);
		push_up();
	}
};
inline trie_01 *merge(trie_01 *a,trie_01 *b){
	if(!a)return b;
	if(!b)return a;
	a->s+=b->s;a->v^=b->v;
	a->d[0]=merge(a->d[0],b->d[0]);
	a->d[1]=merge(a->d[1],b->d[1]);
	delete b;
	return a;
}
constexpr int kN=525011;
int a[kN],n;
trie_01 *rt[kN];
long long ans;
std::basic_string<int>g[kN];
void dfs(int u){
	rt[u]=new trie_01;
	for(int v:g[u])dfs(v),rt[u]=merge(rt[u],rt[v]);
	rt[u]->add().insert(a[u],0);
	ans+=rt[u]->v;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2,x;i<=n;i++)cin>>x,g[x]+=i;
	dfs(1);
	cout<<ans;
	return 0;
}