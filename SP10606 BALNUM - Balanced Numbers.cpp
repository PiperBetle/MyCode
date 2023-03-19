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
loli f[20][3][3][3][3][3][3][3][3][3][3][2];
loli dfs(int pos,int8_t d0,int8_t d1,int8_t d2,int8_t d3,int8_t d4,int8_t d5,int8_t d6,int8_t d7,int8_t d8,int8_t d9,bool zer,bool lim){
#define chk(x) (!d##x||x%2==d##x-1)
	if(!pos)return chk(0)&&chk(1)&&chk(2)&&chk(3)&&chk(4)&&chk(5)&&chk(6)&&chk(7)&&chk(8)&&chk(9);
#undef chk
#define now f[pos][d0][d1][d2][d3][d4][d5][d6][d7][d8][d9][zer]
	if(!lim&&~now)return now;
	loli ans=0;
	for(int i=zer,num=lim?sta[pos]:9;i<=num;i++)switch(i){
#define cnt(x,y) x==y?(d##x?3-d##x:1):d##y
#define choose(x) case x:ans+=dfs(pos-1,cnt(x,0),cnt(x,1),cnt(x,2),cnt(x,3),cnt(x,4),cnt(x,5),cnt(x,6),cnt(x,7),cnt(x,8),cnt(x,9),0,lim&&i==num);break
		choose(0);choose(1);choose(2);choose(3);choose(4);choose(5);choose(6);choose(7);choose(8);choose(9);
#undef cnt
#undef choose
	}
	if(!lim)now=ans;
	return ans;
#undef now
}
loli solve(loli x){
	if(!~x)return 0;
	sta=0;
	do sta+=int(x%10),x/=10;while(x);
	loli ans=dfs(siz(sta)-1,0,0,0,0,0,0,0,0,0,0,1,1);
	for(int i=siz(sta)-2;i>=1;i--)ans+=dfs(i,0,0,0,0,0,0,0,0,0,0,1,0);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	int T;cin>>T;for(loli l,r;T--;)
		cin>>l>>r,cout<<solve(r)-solve(l-1)<<'\n';
	return 0;
}