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
constexpr int kN=1e6+1;
int n,m;
struct{int w,k,id;}a[kN];
pii b[kN];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i].w>>a[i].k,a[i].id=i;
	std::sort(a+1,a+1+m,[](cauto&x,cauto&y){return x.w==y.w?x.k>y.k:x.w<y.w;});
	int cnt=1,l=2,r=3;
	for(int i=1;i<=m;i++)
		if(a[i].k){
			b[a[i].id]={1,++cnt};
			if(cnt>n)return cout<<"-1",0;
		}else{
			if(r>cnt)return cout<<"-1",0;
			b[a[i].id]={l,r};
			if(++l==r)l=2,r++;
		}
	if(cnt!=n)return cout<<"-1",0;
	for(int i=1;i<=m;i++)cout<<b[i].first<<' '<<b[i].second<<'\n';
	return 0;
}