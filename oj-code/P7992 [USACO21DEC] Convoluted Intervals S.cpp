#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
#define int long long
int a[5007],b[5007],s[10007],ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m;cin>>n>>m;
	for(int i=1,x,y;i<=n;i++)cin>>x>>y,a[x]++,b[y]++;
	for(int i=0;i<=m;i++)for(int j=0;j<=m;j++)s[i+j]+=a[i]*a[j],s[i+j+1]-=b[i]*b[j];
	for(int i=0;i<=(m<<1);i++)cout<<(ans+=s[i])<<'\n';
	return 0;
}