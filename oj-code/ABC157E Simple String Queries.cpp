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
constexpr int kN=500001;
int n,m;
std::string a;
struct{
	int tr[kN];
	void updata(int x,int k){for(;x<=n;x+=x&-x)tr[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=tr[x];return k;}
}s[26];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>a>>m;
	for(int i=0;i<siz(a);i++)s[a[i]-'a'].updata(i+1,1);
	for(int l,r;m--;){
		cin>>l;
		if(l==1){
			char c;cin>>l>>c;
			s[a[l-1]-'a'].updata(l,-1);
			s[c-'a'].updata(l,1);
			a[l-1]=c;
		}else{
			int cnt=0;cin>>l>>r;
			for(int i=0;i<26;i++)if(s[i].query(r)-s[i].query(l-1))cnt++;
			cout<<cnt<<'\n';
		}
	}
	return 0;
}