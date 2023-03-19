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
constexpr int N=1e6+1;
std::string s[N];
int n,m;
pii a,b,c,d,p;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		a=b=c=d={0,0};
		cin>>n>>m;
		for(int i=1;i<=n;i++)s[i].reserve(m+1),cin>>s[i],s[i]=' '+s[i];
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]=='B'){
			if(!a.fi||i+j>a.fi+a.se)a={i,j};
			if(!b.fi||i+j<b.fi+b.se)b={i,j};
			if(!c.fi||i-j>c.fi-c.se)c={i,j};
			if(!d.fi||i-j<d.fi-d.se)d={i,j};
		}
		auto B={a,b,c,d};
		int ans=0x3f3f3f3f;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			int dis=0;
			for(auto[x,y]:B)dis=std::max(dis,abs(i-x)+abs(j-y));
			if(dis<ans)ans=dis,p={i,j};
		}
		cout<<p.fi<<' '<<p.se<<'\n';
	}
	return 0;
}