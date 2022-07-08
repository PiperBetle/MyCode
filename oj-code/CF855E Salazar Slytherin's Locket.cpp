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
std::basic_string<int>sta;
int b;
loli f[11][65][1024][2];
loli dfs(int pos,int sum,bool zer,bool lim){
	if(!pos)return !sum;
	if(!lim&&~f[b][pos][sum][zer])return f[b][pos][sum][zer];
	loli ans=0;
	for(int i=zer,num=lim?sta[pos]:b-1;i<=num;i++)
		ans+=dfs(pos-1,sum^(1<<i),0,lim&&i==num);
	if(!lim)f[b][pos][sum][zer]=ans;
	return ans;
}
loli solve(loli x){
	sta.clear();
	do sta+=int(x%b),x/=b;while(x);
	sta=0+sta;
	loli ans=dfs(siz(sta)-1,0,1,1);
	for(int i=siz(sta)-2;i>=1;i--)ans+=dfs(i,0,1,0);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	int T;cin>>T;
	for(loli l,r;T--;)cin>>b>>l>>r,cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}