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
int a[8];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7];
	if(a[1]%2+a[4]%2+a[5]%2>=2&&a[1]&&a[4]&&a[5])ans+=3,a[1]--,a[4]--,a[5]--;
	ans+=a[1]/2*2;
	ans+=a[2];
	ans+=a[4]/2*2;
	ans+=a[5]/2*2;
	cout<<ans;
	return 0;
}