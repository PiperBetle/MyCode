#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e6+1;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	std::string a;a.reserve(kN);
	cin>>a;a='0'+a;
	int n=siz(a)-1,ans=0;
	for(int i=n;~i;i--)
		if(a[i]>'5'||(a[i]=='5'&&a[i-1]>='5'))ans+=10-a[i]+'0',a[i-1]++;
		else ans+=a[i]-'0';
	cout<<ans;
	return 0;
}