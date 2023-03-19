#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
int n,d;
bool a[N];
std::queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>d;
		for(int i=0;i<n;i++)if(cin>>a[i],!a[i])q.push(i);
		int ans=0;
		while(!q.empty()){
			for(int i=siz(q);i;i--){
				int u=q.front(),v=(u+d)%n;q.pop();
				if(a[v])q.push(v),a[v]=false;
			}
			ans++;
		}
		for(int i=0;i<n;i++)if(a[i]){ans=0;break;}
		cout<<ans-1<<'\n';
	}
	return 0;
}