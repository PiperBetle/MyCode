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
constexpr int N=111;
template<typename any>inline void cmin(any &x,any &y){if(x>y)x=y;}
std::string s[N],b;
int n,f[N],pre[N];
pii dt[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>b>>n;b=' '+b;
		memset(f,0x3f,sizeof f);f[0]=0;
		for(int i=1;i<=n;i++)cin>>s[i];
		for(int i=1;i<siz(b);i++)for(int j=1;j<=n;j++){
			if(siz(s[j])<=i&&b.substr(i-siz(s[j])+1,siz(s[j]))==s[j]){
				for(int k=i-siz(s[j]);k<i;k++){
					if(f[k]+1<f[i]){
						f[i]=f[k]+1;
						pre[i]=k;
						dt[i]={j,i-siz(s[j])+1};
					}
				}
			}
		}
		if(f[siz(b)-1]==0x3f3f3f3f){cout<<"-1\n";continue;}
		cout<<f[siz(b)-1]<<'\n';
		for(int i=siz(b)-1;i;i=pre[i])cout<<dt[i].fi<<' '<<dt[i].se<<'\n';
	}
	return 0;
}