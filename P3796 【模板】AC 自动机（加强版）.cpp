#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
#include<ranges>
using std::cin;using std::cout;
constexpr int kN=151;
int vis[kN],n;
struct ac_node{
	int son[26],cnt,fail;
	int &operator[](const int &x){return son[x];}
};
struct ac_automaton:std::vector<ac_node>{
#define a (*this)
	void add_string(const std::string &s,int id){
		if(a.empty())a.emplace_back();
		int p=0;
		for(int c:s|std::views::transform([](char c){return c-'a';})){
			if(!a[p][c])a.emplace_back(),a[p][c]=a.size()-1;
			p=a[p][c];
		}
		a[p].cnt=id;
	}
	void failure(){
		std::queue<int>q;
		for(int v:a[0].son)if(v)q.emplace(v),a[v].fail=0;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(int i=0;i<26;i++){
				int v=a[u][i];
				if(!v)a[u][i]=a[a[u].fail][i];
				else a[v].fail=a[a[u].fail][i],q.emplace(v);
			}
		}
	}
	void query(const std::string &s){
		a.failure();int id=0;
		for(int c:s|std::views::transform([](char c){return c-'a';})){
			for(int p=a[id][c];p;p=a[p].fail)vis[a[p].cnt]++;
			id=a[id][c];
		}
	}
#undef a
};
ac_automaton tr;
std::string s[151];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	tr.reserve(150*70+1);
	while(cin>>n,n){
		memset(vis+1,0,sizeof(int)*n);
		tr.clear();
		for(int i=1;i<=n;i++)cin>>s[i],tr.add_string(s[i],i);
		cin>>s[0];tr.query(s[0]);
		int ans=*std::max_element(vis+1,vis+1+n);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)if(vis[i]==ans)cout<<s[i]<<'\n';
	}
	return 0;
}