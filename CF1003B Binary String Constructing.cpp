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
char A='0',B='1';
int a,b,x;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>a>>b>>x;
	if(a<b)std::swap(a,b),std::swap(A,B);
	for(int i=1;i<=x/2;i++)cout<<A<<B,a--,b--;
	if(x&1)cout<<std::string(a,A)<<std::string(b,B);
	else cout<<std::string(b,B)<<std::string(a,A);
	return 0;
}