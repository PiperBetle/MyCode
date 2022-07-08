#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1001;
int n,f[kN],c[kN],w[kN];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)w[i]-=c[i];
	for(int i=1;i<=n;i++)for(int j=kN-1;j>=c[i];j--)
		f[j]=std::max(f[j],f[j-c[i]]+w[i]);
	cout<<f[kN-1];
	return 0;
}