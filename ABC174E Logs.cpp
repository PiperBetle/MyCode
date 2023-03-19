#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2e5+1;
int n,m,a[kN];
bool check(int x){
	int cnt=m;
	for(int i=1;i<=n;i++)if(a[i]>x&&(cnt-=a[i]/x)<0)break;
	return cnt>=0;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=*std::max_element(a+1,a+1+n),mid;
	while(l<r)if(check(mid=(l+r)/2))r=mid;else l=mid+1;
	cout<<l;
	return 0;
}