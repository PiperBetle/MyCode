#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=20;
int n,a[kN],dep;
std::basic_string<int>b;
bool dfs(int now,int h,int pre){
	if(now==dep)return !h;
	for(int i=2;i<=n;i++){
		if(i==pre||abs(a[i+1]-a[i])==1)continue;
		std::reverse(a+1,a+1+i);
		int nh=h-(abs(a[i+1]-a[i])==1);
		if(now+nh<=dep&&dfs(now+1,nh,i))return true;
		std::reverse(a+1,a+1+i);
	}
	return 0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;a[n+1]=n+1;
	for(int i=1;i<=n;i++)cin>>a[i],b+=a[i];
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());
	for(int i=1;i<=n;i++)a[i]=int(std::lower_bound(all(b),a[i])-b.begin())+1;
	for(dep=0;;dep++)if(dfs(0,[]{
		int h=0;for(int i=1;i<=n;i++)h+=(abs(a[i]-a[i+1])!=1);return h;
	}(),0))return cout<<dep,0;
}