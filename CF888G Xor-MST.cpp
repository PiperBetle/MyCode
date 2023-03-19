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
constexpr int N=2e5+1,inf=0x3f3f3f3f;
struct node{node *ch[2]={};int L=inf,R=-inf;}*rt=new node;
int n,a[N];
void insert(node *&u,int id,int dep){
	if(!u)u=new node;
	u->L=std::min(u->L,id),u->R=std::max(u->R,id);
	if(!~dep)return;
	insert(u->ch[a[id]>>dep&1],id,dep-1);
}
int query(node *u,int k,int dep){
	if(!~dep)return 0;
	int v=k>>dep&1;
	if(u->ch[v])return query(u->ch[v],k,dep-1);
	return query(u->ch[v^1],k,dep-1)+(1<<dep);
}
loli dfs(node *u,int dep){
	if(!~dep)return 0;
	if(u->ch[0]&&u->ch[1]){
		int sum=inf;
		for(int i=u->ch[0]->L;i<=u->ch[0]->R;i++)
			sum=std::min(sum,query(u->ch[1],a[i],dep-1)+(1<<dep));
		return dfs(u->ch[0],dep-1)+dfs(u->ch[1],dep-1)+sum;
	}
	if(u->ch[0])return dfs(u->ch[0],dep-1);
	if(u->ch[1])return dfs(u->ch[1],dep-1);
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)insert(rt,i,30);
	cout<<dfs(rt,30);
	return 0;
}