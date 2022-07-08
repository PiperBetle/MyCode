#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using std::cin;using std::cout;
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
	a.reserve(2*int(s.size())+2);
	a+='~';a+='|';
	for(int i=0;i<int(s.size());i++)(a+=s[i])+='|';
	pw[0]=1;
	for(int i=1;i<int(a.size());i++)pw[i]=pw[i-1]*MOD;
	h1[0]=h2[int(a.size())]=1;
	for(int i=1;i<int(a.size());i++)h1[i]=h1[i-1]*MOD+a[i];
	for(int i=int(a.size())-1;i;i--)h2[i]=h2[i+1]*MOD+a[i];
	for(int i=1;i<int(a.size());i++)
		while(ans<i&&i+ans<int(a.size())&&get_h1(i-ans,i+ans)==get_h2(i-ans,i+ans))ans++;
	cout<<ans-1;
	return 0;
}