#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=3e4+1;
struct strid:std::string{int id;}a[N];
int n;
std::basic_string<int>g[26];
std::queue<int>q;
int ind[26];
bool vis[N];
struct node{
	node *ch[26]={};
	bool end=false;
	node *operator[](int x){return ch[x];}
}*rt=new node;
void insert(const std::string &s){
	node *p=rt;
	for(char c:s){
		if(!p->ch[c-'a'])p->ch[c-'a']=new node;
		p=p->ch[c-'a'];
	}
	p->end=true;
}
void check(const strid &s){
	node *p=rt;
	for(int j=0;j<26;j++)g[j].clear(),ind[j]=0;
	for(char c:s){
		for(int i=0;i<26;i++){
			if(p->end)return;
			if(c!=i+'a'&&p->ch[i])g[i]+=c-'a',ind[c-'a']++;
		}
		p=p->ch[c-'a'];
	}
	for(int j=0;j<26;j++)if(!ind[j])q.push(j);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u])if(!--ind[v])q.push(v);
	}
	if(*std::max_element(ind,ind+26))return;
	vis[s.id]=true;
}
signed main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i].id=i;
	for(int i=1;i<=n;i++)insert(a[i]);
	for(int i=1;i<=n;i++)check(a[i]);
	cout<<std::count(vis+1,vis+1+n,true)<<'\n';
	for(int i=1;i<=n;i++)if(vis[i])cout<<a[i]<<'\n';
	return 0;
}