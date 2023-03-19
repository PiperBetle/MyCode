#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<queue>
#define int loli
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
int n,m,sum,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;sum=ans=0;
		std::priority_queue<int>q;
		for(int i=1,x;i<=m;i++)cin>>x,sum+=x,q.push(x);
		if(sum<n)cout<<"-1\n";else{
			while(!q.empty()){
				int x=q.top();q.pop();
				if(x<=n)n-=x,sum-=x;
				else if(sum-x<n)q.push(x/2),q.push(x/2),ans++;
				else sum-=x;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}