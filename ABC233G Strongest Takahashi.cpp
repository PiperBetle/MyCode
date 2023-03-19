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
constexpr int kN=51;
int n,a[kN][kN],sum[kN][kN],f[kN][kN][kN][kN];
int dfs(int x1,int y1,int x2,int y2){
	if(x1==x2&&y1==y2)return a[x1][y1];
	if(~f[x1][y1][x2][y2])return f[x1][y1][x2][y2];
	int res=0x3f3f3f3f;
	if(x2-x1==y2-y1)res=std::min(res,x2-x1+1);
	for(int i=x1;i<x2;i++)res=std::min(res,dfs(x1,y1,i,y2)+dfs(i+1,y1,x2,y2));
	for(int j=y1;j<y2;j++)res=std::min(res,dfs(x1,y1,x2,j)+dfs(x1,j+1,x2,y2));
	return f[x1][y1][x2][y2]=res;
}
signed main(){
//	freopen("clear.in","r",stdin);
//	freopen("clear.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	memset(f,-1,sizeof f);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		char c;cin>>c;
		if(c=='#')a[i][j]=1;
		// sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	}
	cout<<dfs(1,1,n,n);
	// for(int x2=1;x2<=n;x2++)for(int y2=1;y2<=n;y2++)for(int w=std::min(x2,y2)-1;w;w--){
	// 	int x1=x2-w,y1=x2-w;
	// 	// f[1][1][x1][y1]=
	// }
	return 0;
}
/*
30分1个包
70分1个包
差不多得了
*/