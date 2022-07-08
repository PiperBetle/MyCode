#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1001,MOD=1e9+7;
loli f[kN][11][11][2][2];
std::basic_string<int>sta;
loli dfs(int pos,int d1,int d2,bool zer,bool cnt,bool lim){
	if(!pos)return cnt;
	if(!lim&&~f[pos][d1][d2][zer][cnt])return f[pos][d1][d2][zer][cnt];
	loli ans=0;
	for(int i=zer?1:0,num=lim?sta[pos]:9;i<=num;i++)
		ans+=dfs(pos-1,i,d1,0,cnt||i==d1||i==d2,lim&&i==num);
	if(!lim)f[pos][d1][d2][zer][cnt]=ans;
	return ans;
}
loli solve(loli x){
	sta.clear();
	do{sta+=int(x%10);x/=10;}while(x);
	sta=0+sta;
	loli ans=dfs(siz(sta)-1,10,10,1,0,1);
	for(int i=siz(sta)-2;i>=1;i--)ans+=dfs(i,10,10,1,0,0);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	loli l,r;cin>>l>>r;
	cout<<r-l+1-solve(r)+solve(l-1);
	return 0;
}