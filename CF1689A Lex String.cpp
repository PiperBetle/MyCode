#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
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
int n,m,k,cnt1,cnt2;
std::map<char,int>a,b;
char c;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)cin>>c,a[c]++;
		for(int i=1;i<=m;i++)cin>>c,b[c]++;
		while(siz(a)&&siz(b)){
			if((cnt1<k&&a.begin()->fi<b.begin()->fi)||cnt2==k){
				cout<<a.begin()->fi;
				cnt1++;cnt2=0;
				if(!--a.begin()->se)a.erase(a.begin());
			}else{
				cout<<b.begin()->fi;
				cnt1=0;cnt2++;
				if(!--b.begin()->se)b.erase(b.begin());
			}
		}
		cout<<'\n';
		cnt1=cnt2=0;
		a.clear();b.clear();
	}
	return 0;
}