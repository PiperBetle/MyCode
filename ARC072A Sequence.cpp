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
int n;
loli a1,a2,s1,s2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;s1+=x,s2+=x;
		if(s1<=0&&i%2==1)a1+=1-s1,s1=1;
		if(s1>=0&&i%2==0)a1+=s1+1,s1=-1;
		if(s2>=0&&i%2==1)a2+=s2+1,s2=-1;
		if(s2<=0&&i%2==0)a2+=1-s2,s2=1;
	}
	cout<<std::min(a1,a2);
	return 0;
}