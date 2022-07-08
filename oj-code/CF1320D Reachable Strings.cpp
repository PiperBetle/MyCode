#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define siz(x) (int)(x).size()
using std::cin;using std::cout;
constexpr long long BS=12398737,MD=998244353;
constexpr int kN=2e5+1;
std::string a;
int n,q,cnt[kN];
long long pw[kN],h[2][kN];
inline auto get_h(int l,int r){return h[l&1][r]-h[l&1][l-1]*pw[cnt[r]-cnt[l-1]];}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;a.reserve(n+1);cin>>a>>q;a='~'+a;
	pw[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=pw[i-1]*BS%MD;
		h[0][i]=h[0][i-1],h[1][i]=h[1][i-1],cnt[i]=cnt[i-1];
		if(a[i]=='0')(h[0][i]*=BS)+=1+(i&1),(h[1][i]*=BS)+=1+!(i&1),cnt[i]++;
		h[0][i]%=MD,h[1][i]%=MD;
	}
	while(q--){
		int l,r,m;cin>>l>>r>>m;
		cout<<((get_h(l,l+m-1)%MD+MD)%MD==(get_h(r,r+m-1)%MD+MD)%MD?"Yes\n":"No\n");
	}
	return 0;
}