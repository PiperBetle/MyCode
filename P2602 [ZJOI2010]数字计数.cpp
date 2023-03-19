#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
using std::cin;using std::cout;
int f[15][2][15][2],sta[15];
int dfs(int pos,bool lim,int sum,bool lead,int dig){
	if(!pos)return sum;
	if(~f[pos][lim][sum][lead])return f[pos][lim][sum][lead];
	int ans=0,up=(lim?sta[pos]:9);
	for(int i=0;i<=up;i++)ans+=dfs(pos-1,lim&&(i==up),sum+((i||lead)&&(i==dig)),lead||i,dig);
	return f[pos][lim][sum][lead]=ans;
}
int solve(int x,int dig){
	int len=0;
	while(x)sta[++len]=x%10,x/=10;
	memset(f,-1,sizeof f);
	return dfs(len,1,0,0,dig);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	int a,b;cin>>a>>b;
	for(int i=0;i<=9;i++)cout<<solve(b,i)-solve(a-1,i)<<' ';
	return 0;
}