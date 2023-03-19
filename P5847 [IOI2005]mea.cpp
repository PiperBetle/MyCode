#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
constexpr int inf=0x3f3f3f3f3f3f3f3f;
int s[5000007],m[5000007];
signed main(){
//	freopen(".in","r",stdin);freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,l=-inf,r=inf;cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i],s[i]=s[i-1]+(i&1?+m[i]:-m[i]);
	for(int i=1;i<=n;i++)i&1?r=std::min(r,(s[i-1]<<1)+m[i]):l=std::max(l,(s[i-1]<<1)-m[i]);
	cout<<std::max(r-l+1,0ll);
	return 0;
}