#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=10;
int f[N][N][N][N];
int dfs(int x1,int x2,int y1,int y2){
	if(x1==0&&x2==0)return 1;
	if(y1==0&&y2==0)return 0;
	if(x1>x2)std::swap(x1,x2);
	if(y1>y2)std::swap(y1,y2);
	int &ans=f[x1][x2][y1][y2];
	if(~ans)return ans;else ans=0;
	if(x1&&y1)ans|=!dfs(y1,y2,(x1+y1)%10,x2);
	if(x1&&y2)ans|=!dfs(y1,y2,(x1+y2)%10,x2);
	if(x2&&y1)ans|=!dfs(y1,y2,x1,(x2+y1)%10);
	if(x2&&y2)ans|=!dfs(y1,y2,x1,(x2+y2)%10);
	return ans;
}
signed main(){
//	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	memset(f,-1,sizeof f);
	// cout<<(dfs(1,1,1,1)?"First":"Second");
	for(int x1=0;x1<=9;x1++)for(int x2=0;x2<=9;x2++)
		for(int y1=0;y1<=9;y1++)for(int y2=0;y2<=9;y2++)
			cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<' '<<(dfs(x1,x2,y1,y2)?"First\n":"Second\n");
	return 0;
}