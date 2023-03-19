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
	int T;cin>>T;for(int n,k;T--;){
		cin>>n>>k;
		if(int m=n-(k-1)*1;m>=1&&m&1){
			cout<<"YES\n";
			for(int i=1;i<k;i++)cout<<1<<' ';
			cout<<m<<'\n';
		}else if(int m=n-(k-1)*2;m>=1&&~m&1){
			cout<<"YES\n";
			for(int i=1;i<k;i++)cout<<2<<' ';
			cout<<m<<'\n';
		}else cout<<"NO\n";
	}
	return 0;
}