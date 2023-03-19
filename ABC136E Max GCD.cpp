#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=501;
int n,m,a[kN];
inline bool check(int x){
	static int b[kN];
	for(int i=1;i<=n;i++)b[i]=a[i]%x;
	std::sort(b+1,b+1+n);
	int cnt=0;
	for(int l=1,r=n;l<=r;){
		int x1=b[l],x2=x-b[r];
		if(x1<x2)cnt+=x1,l++,b[r]+=x1;
		if(x1>x2)cnt+=x2,b[l]-=x2,r--;
		if(x1==x2)cnt+=x1,l++,r--;
	}
	return cnt<=m;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int sum=0,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	for(int i=1;i*i<=sum;i++){
		if(sum%i)continue;
		if(check(i))ans=std::max(ans,i);
		if(i*i!=n&&check(sum/i))ans=std::max(ans,sum/i);
	}
	cout<<ans;
	return 0;
}