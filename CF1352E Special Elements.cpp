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
constexpr int N=8001;
int n,m,a[N],s[N];
bool b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		memset(b+1,0,sizeof(int)*n);
		cin>>n,m=0;
		for(int i=1;i<=n;i++)cin>>a[i],s[i]=s[i-1]+a[i];
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
			if(s[j]-s[i-1]<=n)b[s[j]-s[i-1]]=true;
		for(int i=1;i<=n;i++)m+=b[a[i]];
		cout<<m<<'\n';
	}
	return 0;
}