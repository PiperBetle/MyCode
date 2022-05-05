#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
using std::cin;using std::cout;
std::bitset<2007>a[2007];
std::istream &operator>>(std::istream &in,std::bitset<2007ull>::reference t){char c;in>>c;t=c=='1';return in;}
std::ostream &operator<<(std::ostream &out,std::bitset<2007ull>::reference t){out<<(t?"?y7M#\n":"Earth\n");return out;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n,m,ans=0;cin>>n>>m;n++;
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1,r=1;i<n;r=++i){
		while(r<=m&&!a[r][i])r++;
		ans=std::max(ans,r);
		if(r==m+1)return cout<<"Cannot Determine",0;
		if(r!=i)std::swap(a[i],a[r]);
		for(int j=1;j<=m;j++)if(i!=j&&a[j][i])a[j]^=a[i];
	}
	cout<<ans<<'\n';for(int i=1;i<n;i++)cout<<a[i][n];
	return 0;
}