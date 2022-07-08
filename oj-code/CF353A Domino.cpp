#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using lolo=long long;
using i128=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e4+1;
pii a[kN];
int n;
lolo sum1,sum2;
signed main(){
//	freopen("domino.in","r",stdin);
//	freopen("domino.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second,sum1+=a[i].first,sum2+=a[i].second;
	if(sum1%2==0&&sum2%2==0)return cout<<0,0;
	if(sum1%2==1&&sum2%2==1){
		for(int i=1;i<=n;i++)if((a[i].first+a[i].second)%2==1)return cout<<1,0;
		return cout<<"-1",0;
	}
	return cout<<"-1",0;
	return 0;
}