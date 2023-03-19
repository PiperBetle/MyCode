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
constexpr int N=500001;
std::string b;
int n,kmp[N],f[N],h[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>b;n=siz(b);b=' '+b;
	for(int i=2,j=0;i<=n;i++){
		while(j&&b[i]!=b[j+1])j=kmp[j];
		kmp[i]=(b[i]==b[j+1]?++j:j);
	}
	for(int i=1;i<=n;i++)
		h[f[i]=(h[f[kmp[i]]]>=i-kmp[i]?f[kmp[i]]:i)]=i;
	cout<<f[n];
	return 0;
}