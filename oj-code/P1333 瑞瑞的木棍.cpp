#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
namespace ext=__gnu_pbds;
using std::cin;using std::cout;
ext::gp_hash_table<std::string,int>sti;
std::string a,b;
constexpr int kN=500001;
int fat[kN],deg[kN],n;
inline int find(int x){return x==fat[x]?x:fat[x]=find(fat[x]);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=1;i<kN;i++)fat[i]=i;
	while(cin>>a>>b){
		int x=sti[a]?sti[a]:sti[a]=++n;
		int y=sti[b]?sti[b]:sti[b]=++n;
		deg[x]++,deg[y]++;
		if((x=find(x))!=(y=find(y)))fat[x]=y;
	}
	int sum=deg[1]&1;
	for(int i=2;i<=n;i++){
		if(find(i)!=find(i-1))return cout<<"Impossible",0;
		if((deg[i]&1)&&(++sum>2))return cout<<"Impossible",0;
	}
	std::cout<<"Possible";
	return 0;
}