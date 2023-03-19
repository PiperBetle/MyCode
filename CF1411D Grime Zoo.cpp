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
constexpr int N=1e5+2;
std::string s;
int n,x,y,pre[N],suf[N];
loli f1[N],f2[N],ans=0x3f3f3f3f3f3f3f3f;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>s>>x>>y;n=siz(s);s='0'+s;
	if(x<y){std::swap(x,y);for(int i=1;i<=n;i++)s[i]^=isdigit(s[i]);}
	for(int i=1;i<=n;i++){
		if(s[i]=='0')f1[i]=f1[i-1]+1ll*y*pre[i-1];
		else f1[i]=f1[i-1]+1ll*x*(i-1-pre[i-1]);
		pre[i]=pre[i-1]+(s[i]!='0');
	}
	for(int i=n;i>=1;i--){
		if(s[i]=='1')f2[i]=f2[i+1]+1ll*y*suf[i+1];
		else f2[i]=f2[i+1]+1ll*x*(n-i-suf[i+1]);
		suf[i]=suf[i+1]+(s[i]!='1');
	}
	for(int i=0;i<=n;i++)ans=std::min(ans,f1[i]+f2[i+1]+1ll*x*(i-pre[i])*(n-i-suf[i+1])+1ll*y*pre[i]*suf[i+1]);
	cout<<ans;
	return 0;
}