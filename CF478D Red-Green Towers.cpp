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
constexpr int MOD=1e9+7,kN=2e5+1;
constexpr int add0(int x,int y){return (x+=y)<MOD?x:x-MOD;}
constexpr int&add1(int&x,int y){return (x+=y)<MOD?x:x-=MOD;}
constexpr int sub0(int x,int y){return (x-=y)<0?x+MOD:x;}
constexpr int&sub1(int&x,int y){return (x-=y)<0?x+=MOD:x;}
constexpr int mul(const std::initializer_list<int>&x){loli y=1;for(int i:x)(y*=i)%=MOD;return int(y%MOD);}
int r,g,h,f[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>r>>g;f[0]=1;
	for(;h*(h+1)/2<=r+g;h++);
	for(int i=1;i<h;i++)for(int j=r;j>=i;j--)
		add1(f[j],f[j-i]);
	int ans=0;
	for(int i=r;i>=0;i--){
		if(g+i<h*(h-1)/2)break;
		add1(ans,f[i]);
	}
	cout<<ans;
	return 0;
}