#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
#include<ranges>
using std::cin;using std::cout;
constexpr int kN=2e5;
int n;
struct ac_node{
	int son[26],fail;
	std::basic_string<int>g;
	int &operator[](const int &x){return son[x];}
};
struct ac_automaton:std::vector<ac_node>{
#define a (*this)
	std::string s[kN+1];
	int ans[kN+1],pos[kN+1];
	void add_string(const std::string &s,int id){
		if(a.empty())a.emplace_back();
		int p=0;
		for(int c:s|std::views::transform([](char c){return c-'a';})){
			if(!a[p][c])a.emplace_back(),a[p][c]=a.size()-1;
			p=a[p][c];
		}
		pos[id]=p;
	}
	void failure(){
		std::queue<int>q;
		for(int v:a[0].son)if(v)q.emplace(v);
		while(!q.empty()){
			int u=q.front();q.pop();
			a[a[u].fail].g+=u;
			for(int i=0;i<26;i++){
				int v=a[u][i];
				if(!v)a[u][i]=a[a[u].fail][i];
				else a[v].fail=a[a[u].fail][i],q.emplace(v);
			}
		}
	}
	void dfs(int u){for(int v:a[u].g)dfs(v),ans[u]+=ans[v];}
	void query(const std::string &s){
		int p=0;
		for(int c:s|std::views::transform([](char c){return c-'a';}))
			p=a[p][c],ans[p]++;
		dfs(0);
	}
#undef a
};
ac_automaton tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;tr.reserve(kN+1);
	for(int i=1;i<=n;i++)cin>>tr.s[i],tr.add_string(tr.s[i],i);
	tr.failure();cin>>tr.s[0];tr.query(tr.s[0]);
	for(int i=1;i<=n;i++)cout<<tr.ans[tr.pos[i]]<<'\n';
	return 0;
}