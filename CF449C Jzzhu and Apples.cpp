#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ranges>
#include<vector>
#define siz(x) int((x).size())
using std::cin;using std::cout;
struct __runtime{~__runtime(){std::cerr<<"\n\033[33;40muse "<<clock()<<" ms\033[37;40m";}}__RUNTIME;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1;
std::basic_string<int>pt,v;
int n;
bool pr[kN],vis[kN];
std::vector<pii>ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=2;i<=n;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>n)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	for(int i:std::views::reverse(pt)){
		v.clear();
		for(int j=i;j<=n;j+=i)if(!vis[j])v+=j,vis[j]=true;
		if(v.size()==1){vis[v[0]]=false;continue;}
		if(v.size()&1)vis[v[1]]=false,v[1]=v.back(),v.pop_back();
		for(int j=0;j<siz(v);j+=2)ans.emplace_back(v[j],v[j+1]);
	}
	cout<<ans.size()<<'\n';
	for(const auto &i:ans)cout<<i.first<<' '<<i.second<<'\n';
	return 0;
}