#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=150001;
struct node{
	node *ch[2]={};
	int sum=0;
}*rt=new node;
void insert(int x){
	node *p=rt;
	for(int k=30;~k;k--){
		int v=x>>k&1;
		if(!p->ch[v])p->ch[v]=new node;
		p=p->ch[v];
	}
}
int dfs(int x,int y,int k){

}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	return 0;
}