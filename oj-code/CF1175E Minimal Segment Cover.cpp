#include<iostream>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
constexpr int kN=5e5,kLGN=std::__lg(kN)+1;
int f[kN+1][kLGN+1];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m,k=0;cin>>n>>m;
	for(int i=1,l,r;i<=n;i++)cin>>l>>r,f[l][0]=std::max(f[l][0],r),k=std::max(k,r);
	for(int i=1;i<=k;i++)f[i][0]=std::max(f[i][0],f[i-1][0]);
	for(int i=1;i<=kLGN;i++)for(int j=0;j<=k;j++)f[j][i]=f[f[j][i-1]][i-1];
	while(m--){
		int l,r,ans=0;cin>>l>>r;
		for(int i=kLGN;i>=0;i--)if(f[l][i]<r)l=f[l][i],ans+=1<<i;
		cout<<(f[l][0]>=r?ans+1:-1)<<'\n';
	}
	return 0;
}