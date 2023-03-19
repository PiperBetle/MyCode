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
constexpr int N=1001;
int n;
bool vis[N],flag;
std::basic_string<int>b;
void dfs(int u){
	if(flag)return;
	if(u==n){
		flag=true;
		for(int i:b)cout<<i<<' ';
		cout<<'\n';
		return;
	}
	if(!u){
		for(int i=1;i<=n;i++)vis[i]=true,b+=i,dfs(u+1),b.pop_back(),vis[i]=false;
		return;
	}
	for(int i:{-4,-3,-2,2,3,4}){
		if(int x=b.back()+i;1<=x&&x<=n&&!vis[x])
			vis[x]=true,b+=x,dfs(u+1),b.pop_back(),vis[x]=false;
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;flag=false;
		dfs(0);
		if(!flag)cout<<"-1\n";
	}
	return 0;
}