#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
namespace pbds=__gnu_pbds;
using std::cin;using std::cout;
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e3+1;
pbds::gp_hash_table<int,int>s;
int n,a[N],ans;
std::basic_string<int>b;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[a[i]]++;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j){
		if(!a[i]&&!a[j]){ans=std::max(ans,s[0]);continue;}
		int x1=a[i],x2=a[j],x3;
		s[x1]--,s[x2]--;b={x1,x2};
		while(s[x3=x1+x2])s[x3]--,b+=x3,x1=x2,x2=x3;
		ans=std::max(ans,siz(b));
		for(int x:b)s[x]++;
	}
	cout<<ans;
	return 0;
}