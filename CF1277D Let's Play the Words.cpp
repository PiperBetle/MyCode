//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
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
#define rall(x) (x).rbegin(),(x).rend()
#define fi first
#define se second
#define continue(x) {x;continue;}
#define break(x) {x;break;}
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
constexpr bool ying=false,yang=true;
constexpr int N=2e5+1;
int n;
bsc a[N];
bsi ans;
bool vis[N];
std::map<bsc,int>mp;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;mp.clear();ans.clear();
		memset(vis+1,0,sizeof(bool)*n);
		for(int i=1;i<=n;i++)cin>>a[i],mp[a[i]]=i;
		for(int i=1;i<=n;i++)
			if(auto it=mp.find(bsc(rall(a[i])));
				it!=mp.end()&&it->se!=i)vis[i]=true;
		int c00=0,c01=0,c10=0,c11=0;
		for(int i=1;i<=n;i++)
			if(a[i].front()=='0')(a[i].back()=='0'?c00:c01)++;
			else (a[i].back()=='0'?c10:c11)++;
		if(!c01&&!c10&&c00&&c11)continue(cout<<"-1\n");
		int cnt=c01-c10;
		for(int i=1;i<=n&&abs(cnt)>1;i++)if(!vis[i]){
			if(-1>cnt&&a[i].front()=='1'&&a[i].back()=='0')ans+=i,cnt+=2;
			if(+1<cnt&&a[i].front()=='0'&&a[i].back()=='1')ans+=i,cnt-=2;
		}
		if(abs(cnt)>1)continue(cout<<"-1\n")
		cout<<siz(ans)<<'\n';
		for(int i:ans)cout<<i<<' ';
		cout<<'\n';
	}
	return 0;
}