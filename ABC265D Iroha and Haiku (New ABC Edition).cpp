#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
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
constexpr int N=1e6+1;
int a[N],sum[N],n,P,Q,R;
std::set<int>s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>P>>Q>>R;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]+=a[i-1],s.insert(a[i]);
	for(int i=1;i<=n;i++)if(s.count(a[i-1]+=P)&&s.count(a[i-1]+=Q)&&s.count(a[i-1]+=R))return cout<<"Yes",0;
	cout<<"No";
	return 0;
}