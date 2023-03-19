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
int k;
loli f[100+1][3+1];
loli dfs(int pos,int cnt,bool lim){
	if(!pos)return cnt==k;
	if(cnt+pos<k)return 0;
	if(!lim&&~f[pos][cnt])return f[pos][cnt];
	loli ans=0;
	for(int i=0,num=lim?sta[pos]:9;i<=num;i++)
		if(!i)ans+=dfs(pos-1,cnt,lim&&i==num);
		else if(cnt<k)ans+=dfs(pos-1,cnt+1,lim&&i==num);
	if(!lim)f[pos][cnt]=ans;
	return ans;
}
loli solve(const std::string &s){
	sta.clear();
	for(char c:s)sta+=c-'0';
	std::reverse(sta.begin(),sta.end());
	sta=0+sta;
	return dfs(siz(sta)-1,0,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	std::string l;cin>>l>>k;
	cout<<solve(l);
	return 0;
}