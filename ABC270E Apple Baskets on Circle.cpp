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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1;
int n,m,a[N];
void work(int x){
	for(int i=1;i<=n;i++)
		m-=std::min(a[i],x),a[i]-=std::min(a[i],x);
	for(int i=1;i<=n;i++)
		if(a[i]&&m)m--,a[i]--;
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=std::min(a[i],x);
	return sum<=m;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=0,r=m,mid;
	while(l+1<r){
		if(check(mid=(l+r)/2))l=mid;
		else r=mid;
	}
	if(check(r))work(r);else work(l);
	return 0;
}