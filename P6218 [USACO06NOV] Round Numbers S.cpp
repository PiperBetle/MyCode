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
int f[40][40][40][2];
std::basic_string<int>sta;
int dfs(int pos,int sum0,int sum1,bool zer,bool lim){
	if(!pos){return zer||sum0>=sum1;}
	if(!lim&&~f[pos][sum0][sum1][zer])return f[pos][sum0][sum1][zer];
	int ans=0;
	for(int i=0,num=lim?sta[pos]:1;i<=num;i++)
		if(!zer||i)ans+=dfs(pos-1,sum0+(i==0),sum1+(i==1),0,lim&&i==num);
	if(!lim)f[pos][sum0][sum1][zer]=ans;
	return ans;
}
int solve(int x){
	memset(f,-1,sizeof f);
	sta.clear();
	do{sta+=x%2,x/=2;}while(x);
	sta=0+sta;
	int ans=dfs(siz(sta)-1,0,0,1,1);
	for(int i=siz(sta)-2;i>=1;i--)ans+=dfs(i,0,0,1,0);
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