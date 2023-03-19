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
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int N=2e5+3,M=1+std::__lg(N);
std::basic_string<int>b;
pii a[N];
int n,m,k,t,f[N][M];
template<typename any>inline void chkmin(any &x,const any &y){if(y<x)x=y;}
struct cmp{bool operator()(const pii &x,const pii &y)const{return x.se<y.fi;}};
std::set<pii,cmp>s;
inline int calc(int l,int r){
	if(l>r)return 0;
	int p=0;
	for(int i=t;i>=0;i--)if(f[l][i]<=r+1)p+=1<<i,l=f[l][i];
	return p;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>k;t=std::__lg(k);
	for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se,(b+=a[i].fi)+=a[i].se;
	std::sort(all(b));b.erase(std::unique(all(b)),b.end());
	m=siz(b);
	for(int i=1;i<=n;i++)a[i].fi=int(std::lower_bound(all(b),a[i].fi)-b.begin())+1,a[i].se=int(std::lower_bound(all(b),a[i].se)-b.begin())+1;
	for(int i=1;i<=m+2;i++)for(int j=0;j<=t;j++)f[i][j]=m+2;
	for(int i=1;i<=n;i++)chkmin(f[a[i].fi][0],a[i].se);
	for(int i=m;i>=1;i--){
		chkmin(f[i][0],f[i+1][0]);
		for(int j=1;j<=t;j++)f[i][j]=std::min(f[i+1][j],f[f[i][j-1]][j-1]);
	}
	s.emplace(1,m);int sum=calc(1,m);
	if(sum<k)return cout<<"-1",0;
	for(int i=1;i<=n;i++){
		if(auto now=s.find({a[i].fi,a[i].se-1});now!=s.end()&&now->fi<=a[i].fi&&a[i].se-1<=now->se)
			if(int d=calc(now->fi,a[i].fi-1)+calc(a[i].se,now->se)-calc(now->fi,now->se);sum+d>=k-1){
				cout<<i<<'\n';if(!--k)return 0;
				sum+=d;auto[nl,nr]=*now;s.erase(now);
				if(nl<a[i].fi)s.emplace(nl,a[i].fi-1);
				if(a[i].se<=nr)s.emplace(a[i].se,nr);
			}
	}
	return 0;
}