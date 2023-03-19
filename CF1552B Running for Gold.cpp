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
constexpr int N=5e4+1;
int n;
struct player{
	int id,s[5];
	friend bool operator<(const player &x,const player &y){
		int sum=0;
		for(int i=0;i<5;i++)sum+=(x.s[i]<y.s[i]);
		return sum>=3;
	}
}a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)for(a[i].id=i;int &j:a[i].s)cin>>j;
		std::sort(a+1,a+1+n);
		cout<<[]{for(int i=2;i<=n;i++)if(!(a[1]<a[i]))return -1;return a[1].id;}()<<'\n';
	}
	return 0;
}