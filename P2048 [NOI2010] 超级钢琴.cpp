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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=500001,M=std::__lg(N)+1;
int n,k,L,R;
loli sum[N],ans;
struct st_lsit{
	int st[M][N];
	void init(){
		for(int i=1;i<=n;i++)st[0][i]=i;
		for(int i=1,x,y;(1<<i)<=n;i++)for(int j=1;j+(1<<i)-1<=n;j++)
			x=st[i-1][j],y=st[i-1][j+(1<<(i-1))],st[i][j]=sum[x]>sum[y]?x:y;
	}
	int query(int l,int r){
		int k=std::__lg(r-l+1),x=st[k][l],y=st[k][r-(1<<k)+1];
		return sum[x]>sum[y]?x:y;
	}
}st;
struct node{
	int o,l,r,t;
	node(int _o,int _l,int _r):o(_o),l(_l),r(_r),t(st.query(l,r)){}
	friend bool operator<(const node &x,const node &y){
		return sum[x.t]-sum[x.o-1]<sum[y.t]-sum[y.o-1];
	}
};
std::priority_queue<node>q;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k>>L>>R;
	for(int i=1;i<=n;i++)cin>>sum[i],sum[i]+=sum[i-1];
	st.init();
	for(int i=1;i<=n;i++)if(i+L-1<=n)q.emplace(i,i+L-1,std::min(i+R-1,n));
	while(k--){
		auto[o,l,r,t]=q.top();q.pop();
		ans+=sum[t]-sum[o-1];
		if(l!=t)q.emplace(o,l,t-1);
		if(t!=r)q.emplace(o,t+1,r);
	}
	cout<<ans;
	return 0;
}