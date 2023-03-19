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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=30001;
int n,l,r,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)cout<<[]{
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		l=a[1];r=0;
		for(int i=2;i<=n;i++){
			if(a[i]<l+r)l=a[i]-r;
			else r=a[i]-l;
			if(l<0||r<0)return "NO\n";
		}
		return "YES\n"
	}();
	return 0;
}