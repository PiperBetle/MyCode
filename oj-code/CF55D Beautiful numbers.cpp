#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<unordered_map>
#define int long long
using std::cin;using std::cout;
constexpr auto MOD=2520;
int sta[20];
std::unordered_map<int,int>f[27][MOD+7];
inline int __lcm(int x,int y){return !x?y:x/std::__gcd(x,y)*y;}
int dfs(int pos,bool lim,int mul,int lcm){
	if(!pos)return !(mul%lcm);
	if(!lim&&f[pos][mul].count(lcm))return f[pos][mul][lcm];
	int ans=0,num=lim?sta[pos]:9;
	for(int i=0;i<=num;i++)ans+=dfs(pos-1,lim&&i==sta[pos],(mul*10+i)%MOD,__lcm(i,lcm));
	return lim?ans:f[pos][mul][lcm]=ans;
}
int solve(int x){
	int len=0;
	while(x)sta[++len]=x%10,x/=10;
	return dfs(len,1,0,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int l,r,T;cin>>T;while(T--)cin>>l>>r,cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}