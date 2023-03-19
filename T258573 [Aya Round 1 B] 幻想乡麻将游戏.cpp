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
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		int x[5];
		cin>>x[1]>>x[2]>>x[3]>>x[4];
		std::sort(x+1,x+5);
		if(x[1]+1==x[2]&&x[2]+1==x[3]){cout<<"1\n";continue;}
		if(x[1]+1==x[2]&&x[2]+1==x[4]){cout<<"1\n";continue;}
		if(x[1]+1==x[3]&&x[3]+1==x[4]){cout<<"1\n";continue;}
		if(x[2]+1==x[3]&&x[3]+1==x[4]){cout<<"1\n";continue;}
		if(x[1]+1==x[2]&&x[3]==x[4]){cout<<"1\n";continue;}
		if(x[1]+2==x[2]&&x[3]==x[4]){cout<<"1\n";continue;}
		if(x[3]+1==x[4]&&x[1]==x[2]){cout<<"1\n";continue;}
		if(x[3]+2==x[4]&&x[1]==x[2]){cout<<"1\n";continue;}
		cout<<"0\n";
	}
	return 0;
}