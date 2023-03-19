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
constexpr int N=101;
int n,up,dw,lf,rt;
pii a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		up=dw=lf=rt=0;
		for(int i=1,x,y;i<=n;i++){
			cin>>x>>y;
			if(x==0){
				if(y>0)up=std::max(up,y);
				else dw=std::max(dw,-y);
			}
			if(y==0){
				if(x>0)rt=std::max(rt,x);
				else lf=std::max(lf,-x);
			}
		}
		cout<<2*(up+dw+lf+rt)<<'\n';
	}
	return 0;
}