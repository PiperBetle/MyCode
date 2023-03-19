#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ranges>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
struct node{
	node *s[26]={};
	int sg,id=0;
};
node *rt=new node;
int n,m,data;
void insert(const std::string &s,int id){
	auto u=rt;
	for(int c:s|std::views::transform([](char c){return c-'a';}))
		u=(u->s[c]?u->s[c]:u->s[c]=new node);
	u->id=id;
}
void query(node *u){
	if(std::count(u->s,u->s+26,nullptr)==26){u->sg=data;return;}
	for(auto v:u->s)if(v)query(v);
	for(auto v:u->s)if(v&&!v->sg){u->sg=1;return;}
	u->sg=0;
}
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s,insert(s,i);
	data=0;query(rt);bool win=rt->sg;
	data=1;query(rt);bool lose=rt->sg;
	return cout<<(win&&(lose||m%2)?"First":"Second"),0;
}