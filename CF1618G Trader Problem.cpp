#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<map>
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
constexpr int N=400001;
int n,m,q;
int fa[N],sz[N];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
pii a[N],b[N];
loli res,ans[N],sum[N];
std::map<int,std::basic_string<int>>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;
	for(int i=1;i<=n+m;i++)cin>>a[i].fi,a[i].se=i;
	std::sort(a+1,a+1+n+m);
	for(int i=1;i<=n+m;i++){
		if(sz[i]=(a[i].se<=n))res+=a[i].fi;
		fa[i]=i;sum[i]=sum[i-1]+a[i].fi;
		if(i>1)mp[a[i].fi-a[i-1].fi]+=i-1;
	}
	for(int i=1;i<=q;i++)cin>>b[i].fi,b[i].se=i;
	std::sort(b+1,b+1+q);
	auto it=mp.begin();
	for(int i=1;i<=q;i++){
		if(b[i].fi==b[i-1].fi){ans[b[i].se]=res;continue;}
		for(;it!=mp.end()&&it->fi<=b[i].fi;++it)for(int k:it->se){
			int fx=find(k),fy=find(k+1);
			res-=sum[fx]+sum[fy]-sum[fx-sz[fx]]-sum[fy-sz[fy]];
			sz[fy]+=sz[fx];fa[fx]=fy;
			res+=sum[fy]-sum[fy-sz[fy]];
		}
		ans[b[i].se]=res;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<' ';
	return 0;
}