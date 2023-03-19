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
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=2e5+1;
int n,ans[N];
std::basic_string<int>b;
struct node{int h,w,id;friend bool operator<(const node &x,const node &y){return x.h<y.h;}}a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		memset(ans+1,-1,sizeof(int)*n);
		for(int i=1;i<=n;i++){
			cin>>a[i].h>>a[i].w;a[i].id=i;
			if(a[i].h>a[i].w)std::swap(a[i].h,a[i].w);
		}
		std::sort(a+1,a+1+n);
		for(int i=1,k=-1;i<=n;i++){
			b+=i;
			if(~k&&a[i].w>a[k].w)ans[a[i].id]=a[k].id;
			if(a[i].h!=a[i+1].h){
				for(int j:b)if(!~k||a[j].w<a[k].w)k=j;
				b.clear();
			}
		}
		b.clear();
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}