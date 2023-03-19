#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<bitset>
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
constexpr int N=14,M=1e5+1;
constexpr loli inf=0x3f3f3f3f3f3f3f3f;
std::bitset<M>g[N];
int n,m;
loli a[N][M],s[N][N],f[N][1<<N|1],w[N][1<<N|1];
void calc(int dep,int h){

}
bool check(int x){
	static std::basic_string<int>pos;pos.clear();
	for(;x;x^=x&-x)pos+=x&-x;
	for(int i=0;i<siz(pos);i++)for(int j=i+1;j<siz(pos);j++)
		if((g[pos[i]]&g[pos[j]]).any())return false;
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1,x,c;i<=n;i++){
		cin>>c;
		while(c--){
			cin>>x;
			g[i][x]=1;
			for(int k=1;k<=n;k++)s[i][k]+=a[k][x];
		}
	}
	return 0;
}