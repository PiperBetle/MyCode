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
constexpr int N=2e5+1;
int n,a[N],ans;
std::priority_queue<int>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)if(cin>>a[i],a[i]>=0)ans++;
	for(int i=n;i>=1;i--){
		if(a[i]<0){q.push(a[i]);continue;}
		while(!q.empty()&&a[i]>=-q.top())a[i]+=q.top(),q.pop(),ans++;
		if(!q.empty()){int x=q.top();q.pop();q.push(x+a[i]);}
	}
	cout<<ans;
	return 0;
}