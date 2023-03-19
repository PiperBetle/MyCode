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
std::string s;
constexpr int N=1e6+1;
bool vis[N];
inline void solve(){
	int n,a,e;
	cin>>n>>a>>e>>s;n<<=1;s=' '+s;
	memset(vis+1,0,sizeof(bool)*n);
	for(int i=1;i<=n;i++)if(s[i]=='A')a--;
	int dif=abs(a);
	if(dif>e||(e-dif)&1){cout<<"-1\n";return;}
	if(a<0){
		for(int i=1;i<=n&&a<0;i++)if(s[i]=='A')vis[i]=true,s[i]='B',a++;
		if(a<0){cout<<"-1\n";return;}
	}else{
		for(int i=1;i<=n&&a>0;i++)if(s[i]=='B')vis[i]=true,s[i]='A',a--;
		if(a>0){cout<<"-1\n";return;}
	}
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)if(!vis[i])(s[i]=='A'?c1:c2)++;
	if(std::min(c1,c2)*2<e-dif){cout<<"-1\n";return;}
	c1=c2=(e-dif)/2;
	for(int i=1;i<=n;i++)
		if(s[i]=='A'&&c1&&!vis[i])s[i]='B',c1--;
		else if(s[i]=='B'&&c2&&!vis[i])s[i]='A',c2--;
	for(int i=1;i<=n;i++)cout<<s[i];
	cout<<'\n';
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--)solve();
	return 0;
}