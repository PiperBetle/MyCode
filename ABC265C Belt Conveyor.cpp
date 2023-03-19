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
constexpr int N=501;
char c[N][N];
bool vis[N][N];
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>c[i][j];
	for(int x=1,y=1;;){
		if(vis[x][y])return cout<<"-1",0;else vis[x][y]=true;
		switch(c[x][y]){
		case 'U':if(x==1)return cout<<x<<' '<<y,0;x--;break;
		case 'D':if(x==n)return cout<<x<<' '<<y,0;x++;break;
		case 'L':if(y==1)return cout<<x<<' '<<y,0;y--;break;
		case 'R':if(y==m)return cout<<x<<' '<<y,0;y++;break;
		}
	}
	return 0;
}