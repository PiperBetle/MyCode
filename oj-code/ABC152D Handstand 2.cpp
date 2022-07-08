#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
int cnt[10][10];
inline int calc(int x){while(x>9)x/=10;return x;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,ans=0;cin>>n;
	for(int i=1;i<=n;i++)for(int j=i;;j/=10)if(j<10){cnt[j][i%10]++;break;}
	for(int i=1;i<10;i++)for(int j=1;j<10;j++)ans+=cnt[i][j]*cnt[j][i];
	cout<<ans;
	return 0;
}