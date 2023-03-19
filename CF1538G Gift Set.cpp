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
loli x,y,a,b;
bool check(loli m){
	loli cnt=x-b*m;
	if(cnt<0)return 0;
	cnt=std::min(cnt/(a-b),m);
	return a*(m-cnt)+b*cnt<=y;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>x>>y>>a>>b;
		if(a<b)std::swap(a,b);
		if(a==b){cout<<std::min(x,y)/a<<'\n';continue;}
		loli l=0,r=1e9,mid,ans=-1;
		while(l<=r)if(check(mid=(l+r)/2))ans=mid,l=mid+1;else r=mid-1;
		cout<<ans<<'\n';
	}
	return 0;
}