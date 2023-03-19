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
constexpr int N=1000001,MOD=1e9+7;
std::string s;
int n,ans,kmp[N],cnt[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>s;n=siz(s);s='~'+s;
		ans=cnt[1]=1;
		for(int i=2,j=0;i<=n;i++){
			while(j&&s[i]!=s[j+1])j=kmp[j];
			if(s[i]==s[j+1])j++;
			kmp[i]=j,cnt[i]=cnt[j]+1;
		}
		for(int i=2,j=0;i<=n;i++){
			while(j&&s[i]!=s[j+1])j=kmp[j];
			if(s[i]==s[j+1])j++;
			while(j*2>i)j=kmp[j];
			ans=int(1ll*ans*(cnt[j]+1)%MOD);
		}
		cout<<ans<<'\n';
	}
	return 0;
}