	#include<iostream>
	#include<cstdio>
	#include<algorithm>
	#include<cstring>
	#include<cassert>
	#include<tuple>
	#include<map>
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
	constexpr int N=3e5+1;
	int n,m,ans;
	std::map<int,int>f[N];
	int find(int p,int w){
		auto it=f[p].lower_bound(w);
		return it==f[p].begin()?0:(--it)->se;
	}
	signed main(){
	//	freopen(".in","r",stdin);
	//	freopen(".out","w",stdout);
		std::ios::sync_with_stdio(false);cin.tie(nullptr);
		cin>>n>>m;
		for(int u,v,w;m--;){
			cin>>u>>v>>w;
			int r=find(u,w)+1;
			if(r>find(v,w)){
				auto i=f[v].lower_bound(w);f[v][w]=r;
				for(;i!=f[v].end();i=f[v].erase(i))
					if(i->se>r)break;
			}
			cmax(ans,r);
		}
		cout<<ans;
		return 0;
	}