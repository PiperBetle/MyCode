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
constexpr int kN=1.1e7,MOD=1e9+7;
unsigned int pw[2*kN+1],h1[2*kN+1],h2[2*kN+1];
int ans;
std::string s,a;
inline auto get_h1(int l,int r){return h1[r]-h1[l-1]*pw[r-l+1];}
inline auto get_h2(int l,int r){return h2[l]-h2[r+1]*pw[r-l+1];}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	s.reserve(kN);
	cin>>s;
	a.reserve(2*siz(s)+2);
	a+='~';a+='|';
	for(int i=0;i<siz(s);i++)(a+=s[i])+='|';
	pw[0]=1;
	for(int i=1;i<siz(a);i++)pw[i]=pw[i-1]*MOD;
	h1[0]=h2[siz(a)]=1;
	for(int i=1;i<siz(a);i++)h1[i]=h1[i-1]*MOD+a[i];
	for(int i=siz(a)-1;i;i--)h2[i]=h2[i+1]*MOD+a[i];
	for(int i=1;i<siz(a);i++)
		while(ans<i&&i+ans<siz(a)&&get_h1(i-ans,i+ans)==get_h2(i-ans,i+ans))ans++;
	cout<<ans-1;
	return 0;
}