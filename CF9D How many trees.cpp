#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
int f[37][37];
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,h;cin>>n>>h;
	for(int i=0;i<=n;i++)f[0][i]=1;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<j;k++)
		f[j][i]+=f[k][i-1]*f[j-k-1][i-1];
	cout<<f[n][n]-f[n][h-1];
	return 0;
}