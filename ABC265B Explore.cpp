#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define int loli
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
constexpr int N=1e5+1;
int n,m,T,a[N],v[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)cin>>a[i];
	for(int i=1,x,y;i<=m;i++)cin>>x>>y,v[x]=y;
	for(int i=1;i<n;i++)if((T-=a[i])<=0)return cout<<"No",0;else T+=v[i+1];
	cout<<"Yes";
	return 0;
}