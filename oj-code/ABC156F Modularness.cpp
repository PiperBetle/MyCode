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
constexpr int kN=5001;
int k,q,n,x,MOD,a[kN],zr[kN];
loli sum[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>k>>q;
	for(int i=1;i<=k;i++)cin>>a[i];
	for(;q--;){
		cin>>n>>x>>MOD;
		for(int i=1;i<=k;i++)sum[i]=sum[i-1]+a[i]%MOD,zr[i]=zr[i-1]+!(a[i]%MOD);
		cout<<n-1-((n-1)/k*zr[k]+zr[(n-1)%k])-((n-1)/k*sum[k]+sum[(n-1)%k]+x%MOD)/MOD<<'\n';
	}
	return 0;
}