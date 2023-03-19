#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long
#define MOD 1000000000
std::string s;
int f[307][307];
using std::cin;using std::cout;
int dfs(int l,int r){
	if(l==r)return 1;
	if(l>r)return 0;
	if(f[l][r]!=-1)return f[l][r];
	f[l][r]=0;
	for(int i=l+2;i<=r;i++)if(s[l]==s[i])
		(f[l][r]+=dfs(l+1,i-1)*dfs(i,r))%=MOD;
	return f[l][r];
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	memset(f,-1,sizeof f);
	cin>>s;
	cout<<dfs(0,s.size()-1);
	return 0;
}