#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<unordered_map>
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
constexpr int N=51;
inline int calc(int x){return x*(x+1)/2;}
std::unordered_map<char,int>l={{'N',1},{'S',-1},{'W',0},{'E',0}},r={{'N',0},{'S',0},{'W',-1},{'E',1}};
int n,m,x,y,a[N][N],b[N][N];
std::string s;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>y>>x>>s;
	for(int i=0;i<m;i++)a[x][y]+=calc(i-b[x][y]),b[x][y]=i+1,x+=l[s[i]],y+=r[s[i]];
	for(int i=n;i>=1;i--,cout<<'\n')for(int j=1;j<=n;j++)cout<<(a[i][j]+=calc(m-b[i][j]))<<' ';
	return 0;
}