#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,MOD=1e9+7;
inline int&add1(int&_x,int _y){return (_x+=_y)<MOD?_x:_x-=MOD;}
std::string s;
int f[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>s;
	if(s.find('m')!=s.npos||s.find('w')!=s.npos)return cout<<0,0;
	f[0]=f[1]=1;if(s[0]==s[1]&&(s[0]=='n'||s[0]=='u'))f[1]=2;
	for(int i=2;i<siz(s);i++){
		f[i]=f[i-1];
		if(s[i]==s[i-1]&&(s[i]=='n'||s[i]=='u'))add1(f[i],f[i-2]);
	}
	cout<<f[siz(s)-1];
	return 0;
}