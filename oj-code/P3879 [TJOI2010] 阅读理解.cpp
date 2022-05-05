#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<ranges>
using std::cin;using std::cout;
struct trie{
    trie *s[26];
    std::vector<int>data;
    trie(){data.clear();std::fill_n(s,26,nullptr);}
}*root=new trie;
inline void insert(std::string &s,int cnt){
    trie *p=root;
    for(int it:s|std::views::transform([](char c){return c-97;})){
        if(!p->s[it])p->s[it]=new trie;
        p=p->s[it];
    }
    p->data.emplace_back(cnt);
    if(p->data.empty()||p->data.back()!=cnt)p->data.emplace_back(cnt);
}
inline void find(std::string &s){
    trie *p=root;
    for(int it:s|std::views::transform([](char c){return c-97;})){
        if(!p->s[it])return;
        p=p->s[it];
    }
    for(int it:p->data)cout<<it<<' ';
}
signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  std::ios::sync_with_stdio(false);
//  cin.tie(nullptr);
    int n,m;std::string s;
    cin>>n;for(int i=1;i<=n;i++){int t;cin>>t;while(t--)cin>>s,insert(s,i);}
    cin>>m;while(m--){cin>>s;find(s);cout<<'\n';}
    return 0;
}