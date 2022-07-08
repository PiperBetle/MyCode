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
loli f[19+1][3+1];
loli dfs(int pos,int cnt,bool lim){
	if(!pos)return 1;
	if(!lim&&~f[pos][cnt])return f[pos][cnt];
	loli ans=0;
	for(int i=0,num=lim?sta[pos]:9;i<=num;i++)
		if(!i)ans+=dfs(pos-1,cnt,lim&&i==num);
		else if(cnt<3)ans+=dfs(pos-1,cnt+1,lim&&i==num);
	if(!lim)f[pos][cnt]=ans;
	return ans;
}
loli solve(loli x){
	sta.clear();
	do sta+=int(x%10),x/=10;while(x);
	sta=0+sta;
	return dfs(siz(sta)-1,0,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	int T;cin>>T;
	for(loli l,r;T--;)cin>>l>>r,cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}