#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
constexpr int kN=501;
using loli=long long;
using vinti=__int128_t;
using pii=std::pair<int,int>;
char a[kN][kN];
int T,n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>T;while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
		for(int i=1;i<=n;i+=3)memset(a[i]+1,'X',sizeof(char)*m);
		for(int i=2;i<=n;i+=3){
			if(i==n)break;
			if(i+1==n){for(int j=1;j<=m;j++)if(a[i+1][j]=='X')a[i][j]='X';break;}
			if(a[i][2]=='X'||a[i+1][2]=='X')a[i][2]=a[i+1][2]='X';
			else a[i][1]=a[i+1][1]='X';
		}
		for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=m;j++)cout<<a[i][j];
	}
	return 0;
}