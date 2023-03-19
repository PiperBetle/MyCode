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
constexpr int N=1001;
bool a[N][N];
int n,m;
void add(int u){a[u][u+1]=a[u+1][u]=true;}
void add(int u,int v){a[u][v]=a[v][u]=true;}
void add(int u,int v1,int v2){a[u][v1]=a[v1][u]=a[u][v2]=a[v2][u]=true;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=std::__lg(n);
	add(1,3);add(1,4);
	for(int i=1;i<=m;i++)add(i*2+1,i*2+3,i*2+4),add(i*2+2,i*2+3,i*2+4);
	add(3*m+4,2);for(int i=1;i<=m;i++)add(2*m+i+4);
	for(int i=0;i<=m;i++)if(n&(1<<i))add(2*i+4,i==m?2:2*m+i+5);
	cout<<3*m+4<<'\n';
	for(int i=1;i<=3*m+4;i++,cout<<'\n')for(int j=1;j<=3*m+4;j++)cout<<(a[i][j]?'Y':'N');
	return 0;
}