#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=2001;
struct road{int u,v;loli w;};
std::basic_string<road>s;
int n,k[kN],fa[kN];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
pii a[kN];
std::basic_string<int>el;
std::vector<pii>ln;
loli sum;
int dis(const pii &_a,const pii &_b){return abs(_a.first-_b.first)+abs(_a.second-_b.second);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	// for(int i=1,c;i<=n;i++)cin>>c,s+=road(0,i,c);
	for(int i=1,c;i<=n;i++)cin>>c,s+=road{0,i,c};
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)s+=road(i,j,1ll*(k[i]+k[j])*dis(a[i],a[j]));
	std::sort(s.begin(),s.end(),[](const road &_a,const road &_b){return _a.w<_b.w;});
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int cnt=0;auto[u,v,w]:s){
		int fx=find(u),fy=find(v);
		if(fx==fy)continue;
		fa[fx]=fy;sum+=w;
		if(u)ln.emplace_back(u,v);
		else el+=v;
		if(++cnt==n)break;
	}
	cout<<sum<<'\n'<<el.size()<<'\n';
	for(int i:el)cout<<i<<' ';
	cout<<'\n'<<ln.size()<<'\n';
	for(auto[u,v]:ln)cout<<u<<' '<<v<<'\n';
	return 0;
}