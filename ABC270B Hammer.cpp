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
int x,y,z;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>x>>y>>z;
	if(x>0&&(x<y||y<0))return cout<<abs(x),0;
	if(x<0&&(x>y||y>0))return cout<<abs(x),0;
	if(z>0&&(z<y||y<0))return cout<<abs(z)+abs(z-x),0;
	if(z<0&&(z>y||y>0))return cout<<abs(z)+abs(z-x),0;
	cout<<"-1";
	return 0;
}