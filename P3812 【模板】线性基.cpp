#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<array>
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
int n;
struct LineBase:std::array<loli,50>{
#define a (*this)
	auto &operator+=(loli x){
		for(int i=49;~i;i--){
			if(!(x>>i&1))continue;
			if(!a[i])return a[i]=x,*this;
			x^=a[i];
		}
		return *this;
	}
	auto max(){
		loli res=0;
		for(int i=49;i>=0;i--)res=std::max(res,res^a[i]);
		return res;
	}
#undef a
}s;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(loli x;n--;)cin>>x,s+=x;
	cout<<s.max();
	return 0;
}