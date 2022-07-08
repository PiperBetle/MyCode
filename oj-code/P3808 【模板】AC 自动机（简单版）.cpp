#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>
#include<ranges>
using std::cin;using std::cout;
struct ac_node{
	int son[26],cnt,fail;
	int &operator[](const int &x){return son[x];}
};
struct ac_automaton:std::vector<ac_node>{
#define a (*this)
	ac_automaton(){a.emplace_back();}
	void add_string(const std::string &s){
		int p=0;
		for(int c:s|std::views::transform([](char c){return c-'a';})){
			if(!a[p][c])a.emplace_back(),a[p][c]=a.size()-1;
			p=a[p][c];
		}
		a[p].cnt++;
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
	int query(const std::string &s){
		int ans=0,id=0;
		for(int c:s|std::views::transform([](char c){return c-'a';})){
			for(int p=a[id][c];p&&~a[p].cnt;p=a[p].fail)
				ans+=a[p].cnt,a[p].cnt=-1;
			id=a[id][c];
		}
		return ans;
	}
#undef a
};
ac_automaton tr;
std::string s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	tr.reserve(1000001);
	while(n--)cin>>s,tr.add_string(s);
	tr.failure();cin>>s;cout<<tr.query(s);
	return 0;
}