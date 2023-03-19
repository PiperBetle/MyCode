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
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=500001;
struct LineBase{
	int p[21]={},a[21]={};
	LineBase &insert(const LineBase &x,int w,int v){
		*this=x;
		for(int i=20;~i;i--)if(v>>i&1){
			if(!a[i])return p[i]=w,a[i]=v,*this;
			else if(p[i]<w)std::swap(p[i],w),std::swap(a[i],v);
			v^=a[i];
		}
		return *this;
	}
	int query(int l,int res=0){
		for(int i=20;~i;i--)if(a[i]&&p[i]>=l)res=std::max(res,res^a[i]);
		return res;
	}
}a[N];
int n,m;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,a[i].insert(a[i-1],i,x);
	cin>>m;
	for(int l,r;m--;)cin>>l>>r,cout<<a[r].query(l)<<'\n';
	return 0;
}