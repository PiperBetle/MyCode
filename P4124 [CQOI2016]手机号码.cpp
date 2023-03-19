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
loli f[11+1][11][11][2][2][2][2];
loli dfs(int pos,int d1,int d2,bool cnt,bool h4,bool h8,bool zer,bool lim){
	if(h4&&h8)return 0;
	if(!pos)return cnt;
	if(!lim&&~f[pos][d1][d2][cnt][h4][h8][zer])return f[pos][d1][d2][cnt][h4][h8][zer];
	loli ans=0;
	for(int i=zer,num=lim?sta[pos]:9;i<=num;i++)
		ans+=dfs(pos-1,i,d1,cnt||(i==d1&&d1==d2),h4||i==4,h8||i==8,0,lim&&i==num);
	if(!lim)f[pos][d1][d2][cnt][h4][h8][zer]=ans;
	return ans;
}
loli solve(loli x){
	if(x<loli(1e10))return 0;
	sta.clear();
	do sta+=int(x%10),x/=10;while(x);
	sta=0+sta;
	return dfs(siz(sta)-1,10,10,0,0,0,1,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	loli l,r;cin>>l>>r;
	cout<<solve(r)-solve(l-1);
	return 0;
}