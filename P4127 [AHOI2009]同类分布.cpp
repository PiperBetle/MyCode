#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int mod;
std::basic_string<int>sta;
loli f[18+1][18*9+1][18*9+1];
loli dfs(int pos,int sum,int res,bool lim){
	if(!pos)return sum==mod&&res==0;
	if(sum+9*pos<mod)return 0;
	if(!lim&&~f[pos][sum][res])return f[pos][sum][res];
	loli ans=0;
	for(int i=0,num=lim?sta[pos]:9;i<=num;i++)
		ans+=dfs(pos-1,sum+i,(res*10+i)%mod,lim&&i==num);
	if(!lim)f[pos][sum][res]=ans;
	return ans;
}
loli solve(loli x){
	sta.clear();
	do{sta+=int(x%10),x/=10;}while(x);
	sta=0+sta;
	loli ans=0;
	for(mod=1;mod<=9*(siz(sta)-1);mod++)
		memset(f,-1,sizeof f),ans+=dfs(siz(sta)-1,0,0,1);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	loli l,r;cin>>l>>r;
	cout<<solve(r)-solve(l-1);
	return 0;
}