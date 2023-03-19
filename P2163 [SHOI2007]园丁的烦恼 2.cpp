#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=500001;
int n,m;
struct ask{int x,y,id;auto operator<=>(const ask &)const=default;}s[5*N];
std::basic_string<int>b,ans[N];
struct BIT{
	int data[5*N];
	void add(int x,int k=1){for(;x<=n;x+=x&-x)data[x]+=k;}
	int query(int x){int k=0;for(;x;x-=x&-x)k+=data[x];return k;}
}tr;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i].x>>s[i].y;
	for(int i=1,x1,y1,x2,y2;i<=m;i++)cin>>x1>>y1>>x2>>y2,s[++n]={x1-1,y1-1,i},s[++n]={x1-1,y2,i},s[++n]={x2,y1-1,i},s[++n]={x2,y2,i};
	std::sort(s+1,s+1+n);
	b.reserve(n);for(int i=1;i<=n;i++)b+=s[i].y;
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());
	for(int i=1;i<=n;i++){
		int p=int(std::lower_bound(all(b),s[i].y)-b.begin())+1;
		if(s[i].id)ans[s[i].id]+=tr.query(p);else tr.add(p);
	}
	for(int i=1;i<=m;i++)cout<<ans[i][0]-ans[i][1]-ans[i][2]+ans[i][3]<<'\n';
	return 0;
}