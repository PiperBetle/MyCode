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
constexpr int N=51,M=20002;
int n,m,k,sum[N][M],f[N][M],pre[M],suf[M];
signed main(){
//	freopen("range.in","r",stdin);
//	freopen("range.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>sum[i][j],sum[i][j]+=sum[i][j-1];
	for(int i=1;i<=m-k+1;i++)f[n][i]=sum[n][i+k-1]-sum[n][i-1];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=m-k+1;j++)pre[j]=0,pre[j]=std::max(pre[j-1],f[i+1][j]);
		for(int j=m-k+1;j>=1;j--)suf[j]=0,suf[j]=std::max(suf[j+1],f[i+1][j]);
		for(int j=1;j<=m-k+1;j++){
			int tot=sum[i+1][j+k-1]-sum[i+1][j-1]+sum[i][j+k-1]-sum[i][j-1];
			if(j-k>=1)f[i][j]=std::max(f[i][j],pre[j-k]+tot);
			if(j+k<=m)f[i][j]=std::max(f[i][j],suf[j+k]+tot);
			for(int l=std::max(1,j-k+1),r=std::min(m,j+k-1),ux,uy;l<=r;l++){
				if(l<j)ux=j,uy=l+k-1;else ux=l,uy=j+k-1;
				f[i][j]=std::max(f[i][j],f[i+1][l]+tot-sum[i+1][uy]+sum[i+1][ux-1]);
			}
		}
	}
	cout<<*std::max_element(f[1]+1,f[1]+m-k+2);
	return 0;
}