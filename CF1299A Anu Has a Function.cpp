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
constexpr int N=1e5+1;
int n,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=30;~k;k--){
		int p=0;
		for(int i=1;i<=n;i++)if(a[i]>>k&1){
			if(p)goto next;
			else p=i;
		}
		if(p==0)goto next;
		cout<<a[p];
		for(int i=1;i<=n;i++)if(i!=p)cout<<' '<<a[i];
		return 0;
		next:;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}