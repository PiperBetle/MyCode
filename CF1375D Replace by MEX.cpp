//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
using std::tie;using std::ignore;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
using bsc=std::basic_string<char>;
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1002;
int n,a[N],cnt,mex;
bool mk[N],vis[N];
bsi ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;cnt=n;ans.clear();
		memset(mk+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)if(cin>>a[i],a[i]==i-1)mk[i]=true,cnt--;
		while(cnt){
			memset(vis,0,sizeof(bool)*(n+1));
			for(int i=1;i<=n;i++)vis[a[i]]=true;
			for(int i=0;i<=n;i++)if(!vis[i]){mex=i;break;}
			if(mex==n){
				for(int i=1;i<=n;i++)if(!mk[i])
					{ans+=i;a[i]=mex;break;}
			}else{
				ans+=mex+1;
				a[mex+1]=mex;
				mk[mex+1]=true;
				cnt--;
			}
		}
		cout<<siz(ans)<<'\n';
		for(int i:ans)cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}