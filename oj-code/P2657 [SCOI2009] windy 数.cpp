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
std::basic_string<int>sta;
int f[20][20][2];
int dfs(int pos,int pre,bool zer,bool lim){
	if(!pos)return 1;
	if(!lim&&~f[pos][pre][zer])return f[pos][pre][zer];
	int ans=0;
	for(int i=zer?1:0,num=lim?sta[pos]:9;i<=num;i++)
		if(abs(i-pre)>=2)ans+=dfs(pos-1,i,0,lim&&i==num);
	if(!lim)f[pos][pre][zer]=ans;
	return ans;
}
int solve(int x){
	memset(f,-1,sizeof f);
	sta.clear();
	do{sta+=x%10,x/=10;}while(x);
	sta=0+sta;
	int ans=dfs(siz(sta)-1,11,1,1);
	for(int i=siz(sta)-2;i>=1;i--)ans+=dfs(i,11,1,0);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int l,r;cin>>l>>r;
	cout<<solve(r)-solve(l-1);
	return 0;
}