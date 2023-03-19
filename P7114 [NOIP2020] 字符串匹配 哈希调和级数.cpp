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
constexpr int N=1<<20|1,BASE=233;
struct BIT{
	int data[27];
	void add(int x,int k=1){for(;x<=26;x+=x&-x)data[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=data[x];return k;}
}tr;
std::string s;
int n,cnt[26],pre[N],suf[N];
uloli pw[N],hs[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	pw[0]=1;for(int i=1;i<N;i++)pw[i]=pw[i-1]*BASE;
	int T;cin>>T;while(T--){
		memset(tr.data,0,sizeof tr.data);
		cin>>s;n=siz(s);s=' '+s;
		for(int i=1;i<=n;i++)hs[i]=hs[i-1]*BASE+s[i];
		memset(cnt,0,sizeof cnt);
		for(int i=1,sum=0;i<=n;i++)pre[i]=++cnt[s[i]-'a']&1?++sum:--sum;
		memset(cnt,0,sizeof cnt);
		for(int i=n,sum=0;i>=1;i--)suf[i]=++cnt[s[i]-'a']&1?++sum:--sum;
		loli ans=0;
		for(int j=pre[1]+1;j<=26;j++)tr.data[j]++;
		for(int i=2;i<=n;i++){
			auto get_h=[](int l,int r){return hs[r]-hs[l-1]*pw[r-l+1];};
			auto x=get_h(1,i);
			for(int j=i;j<n;j+=i){
				if(get_h(j-i+1,j)!=x)break;
				ans+=tr.data[suf[j+1]+1];
			}
			for(int j=pre[i]+1;j<=26;j++)tr.data[j]++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}