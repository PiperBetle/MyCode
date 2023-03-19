#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using std::cin;using std::cout;
int n,m,sum[507][507],b[26];
char a[507][507];
int calc(int x1,int y1,int x2,int y2){return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];}
signed main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k,n,m;long long ans=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>a[i][j],sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='a');
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++){
		memset(b,0,sizeof b);
		for(int l=1,r=1;l<=m;l++){
			if(a[i][l]!=a[j][l])continue;
			for(;r<=m&&calc(i,l,j,r)<=k;r++)b[a[j][r]-96]+=(a[j][r]==a[i][r]);
			if(--b[a[i][l]-96]>0)ans+=b[a[i][l]-96];
		}
	}
	cout<<ans;
	return 0;
}