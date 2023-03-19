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
using pii=std::pair<loli,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e6+1;
int l,n,m,a[N],b[N];
loli ans;
std::basic_string<loli>x,y;
std::priority_queue<pii,std::vector<pii>,std::greater<>>q;
signed main(){
//	freopen("farewell.in","r",stdin);
//	freopen("farewell.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=n;i++)q.emplace(a[i],i);
	while(!q.empty()&&siz(x)<=l){
		pii u=q.top();q.pop();
		x+=u.fi,u.fi+=a[u.se];
		q.push(u);
	}
	while(!q.empty())q.pop();
	for(int i=1;i<=m;i++)q.emplace(b[i],i);
	while(!q.empty()&&siz(y)<=l){
		pii u=q.top();q.pop();
		y+=u.fi,u.fi+=b[u.se];
		q.push(u);
	}
	for(auto i=0;i<l;i++)ans=std::max(ans,x[i]+y[l-i-1]);
	cout<<ans;
	return 0;
}