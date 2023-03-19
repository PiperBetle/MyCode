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
constexpr int N=2e5+1;
struct node{
	int id;mutable int sum;
	friend bool operator<(const node &x,const node &y){return x.id<y.id;}
};
std::set<node>s;
int n,m,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s.emplace(i,0);
	cin>>m;
	for(int u,x;m--;){
		if(cin>>u,u==1){
			cin>>u>>x;
			for(auto it=s.lower_bound({u,0});it!=s.end();it=s.erase(it)){
				if(x<a[it->id]-it->sum){it->sum+=x;break;}
				else x-=a[it->id]-it->sum;
			}
		}else{
			cin>>u;
			if(s.lower_bound({u,0})->id!=u)cout<<a[u]<<'\n';
			else cout<<s.lower_bound({u,0})->sum<<'\n';
		}
	}
	return 0;
}