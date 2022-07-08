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
std::basic_string<int>sta1,sta2;
loli f[40][2][2];
loli dfs(int pos,bool lim1,bool lim2){
	if(!pos)return 1;
	if(~f[pos][lim1][lim2])return f[pos][lim1][lim2];
	loli ans=0;
	for(int i=0,num1=lim1?sta1[pos]:1;i<=num1;i++)for(int j=0,num2=lim2?sta2[pos]:1;j<=num2;j++)
		if(i+j!=2)ans+=dfs(pos-1,lim1&&i==num1,lim2&&j==num2);
	return f[pos][lim1][lim2]=ans;
}
loli solve(int x1,int x2){
	if(x1<0)return 0;
	memset(f,-1,sizeof f);
	sta1.clear(),sta2.clear();
	do sta1+=x1%2,x1/=2;while(x1);
	do sta2+=x2%2,x2/=2;while(x2);
	sta1=0+sta1,sta2=0+sta2;
	sta1.resize(siz(sta2));
	return dfs(siz(sta2)-1,1,1);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	sta1.reserve(40),sta2.resize(40);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;for(int l,r;T--;)
		cin>>l>>r,cout<<solve(r,r)-2*solve(l-1,r)+solve(l-1,l-1)<<'\n';
	return 0;
}