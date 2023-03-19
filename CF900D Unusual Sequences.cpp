#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int MOD=1e9+7;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
constexpr int mul(const std::initializer_list<int>&x){loli y=1;for(int i:x)(y*=i)%=MOD;return int(y%MOD);}
constexpr int qp(int a,int b,int t=1){for(;b;b>>=1,a=mul({a,a}))if(b&1)t=mul({a,t});return t;}
std::unordered_map<int,int>f;
int dfs(int x){
	if(f.count(x))return f[x];
	int ans=qp(2,x-1);
	for(int i=2;i*i<=x;i++)if(x%i==0){
		sub1(ans,dfs(i));
		if(i*i!=x)sub1(ans,dfs(x/i));
	}
	return f[x]=sub0(ans,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int x,y;cin>>x>>y;
	if(y%x)return cout<<0,0;
	f[1]=1;cout<<dfs(y/x);
	return 0;
}