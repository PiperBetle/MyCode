#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int MOD=1e9+7;
inline int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int kN=35001,kM=102;
int n,m,k,f[kM][kN],g[kM][kN],cnt[kN];
signed main(){
//	freopen("seqcount.in","r",stdin);
//	freopen("seqcount.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;m=int(sqrt(n));
	for(int i=1;i<m;i++)cnt[i]=n/i-n/(i+1);
	cnt[m]=n/m-m;
	for(int i=1;i<=m;i++)f[1][i]=1,g[1][i]=cnt[i];
	for(int i=1;i<=k;i++){
		int sum=0;
		for(int j=1;j<=m;j++)g[i+1][j]=int(1ll*add1(sum,f[i][j])*cnt[j]%MOD);
		for(int j=m;j>=1;j--)f[i+1][j]=add1(sum,g[i][j]);
	}
	cout<<f[k+1][1];
//	std::cerr<<"\033[33;40muse "<<clock()<<" ms\033[37;40m";
	return 0;
}