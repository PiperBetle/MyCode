#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<set>
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
constexpr int N=1001;
std::set<int>s;
int n,a[N],b[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		if(n==1){cin>>n;cout<<"-1\n";continue;}
		for(int i=1;i<=n;i++)s.insert(i);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(*s.begin()==a[i])b[i]=*(siz(s)==1?s.begin():std::next(s.begin()));
			else b[i]=*s.begin();
			s.erase(b[i]);
		}
		if(a[n]==b[n])std::swap(b[n-1],b[n]);
		for(int i=1;i<=n;i++)cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}