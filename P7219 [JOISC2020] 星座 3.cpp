#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=2e5+1;
int n,m;
struct{
	loli tr[N];
	void updata(int x,loli k){for(;x<=n+1;x+=x&-x)tr[x]+=k;}
	loli query(int x){loli k=0;for(;x;x-=x&-x)k+=tr[x];return k;}
}tr;
struct{
	int fa[N];
	void clear(){for(int i=1;i<=n+1;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
}L,R;
std::basic_string<int>h[N];
std::vector<pii>s[N];
loli ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	L.clear(),R.clear();
	for(int i=1,x;i<=n;i++)cin>>x,h[x]+=i;
	cin>>m;
	for(int i=1,x,y,w;i<=m;i++)cin>>x>>y>>w,s[y].emplace_back(x,w);
	for(int i=1;i<=n;i++){
		for(auto[x,w]:s[i]){
			if(loli v=tr.query(x);v>=w)ans+=w;
			else ans+=v,tr.updata(L.find(x)+1,w-v),tr.updata(R.find(x),v-w);
		}
		for(int x:h[i])L.fa[x]=x-1,R.fa[x]=x+1;
	}
	cout<<ans;
	return 0;
}