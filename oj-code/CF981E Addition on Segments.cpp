#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<bitset>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) x.begin(),x.end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e4+1;
using btst=std::bitset<kN>;
int n,q;
std::basic_string<int>s[kN<<2];
#define ls (u*2)
#define rs (u*2+1)
#define mid ((l+r)/2)
btst ans;
void updata(int u,int l,int r,int x,int y,int k){
	if(x<=l&&r<=y){s[u]+=k;return;}
	if(x<=mid)updata(ls,l,mid,x,y,k);
	if(y>mid)updata(rs,mid+1,r,x,y,k);
}
void build(int u,int l,int r,btst b){
	for(int i:s[u])b|=(b<<i);
	if(l==r){ans|=b;return;}
	build(ls,l,mid,b);
	build(rs,mid+1,r,b);
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	for(int l,r,k;q--;)cin>>l>>r>>k,updata(1,1,n,l,r,k);
	btst ss;ss[0]=1;build(1,1,n,ss);
	loli cnt=0;
	for(int i=1;i<=n;i++)cnt+=ans[i];
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++)if(ans[i])cout<<i<<' ';
	return 0;
}