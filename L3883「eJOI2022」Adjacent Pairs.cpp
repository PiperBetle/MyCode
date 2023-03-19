#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<unordered_map>
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
constexpr int N=2e5+1;
int n,a[N],b[N],c1[N],c2[N];
std::unordered_map<int,int>mp[N];
signed main(){
//	freopen("oscar.in","r",stdin);
//	freopen("oscar.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;int ans=0;
		memset(c1+1,0,sizeof(int)*n);memset(c2+1,0,sizeof(int)*n);
		for(int i=1;i<=n;i++)cin>>a[i],mp[i].clear(),a[i][i&1?c1:c2]++,b[i]=a[i];
		std::sort(b+1,b+1+n,[](int x,int y){return c2[x]>c2[y];});
		for(int i=1;i<n;i++){
			if(i&1)mp[a[i+1]][a[i]]++;
			else mp[a[i]][a[i+1]]++;
			i+=a[i]==a[i+2];
		}
		for(int i=1;i<=n;i++){
			for(auto[j,k]:mp[i])cmax(ans,c1[i]+c2[j]-k);
			for(int j=1;j<=n;j++)if(i!=b[j]&&!mp[i].count(b[j]))
				{cmax(ans,c1[i]+c2[b[j]]);break;}
		}
		cout<<n-ans<<'\n';
	}
	return 0;
}