#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<deque>
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
int n,a[N];
loli m;
std::deque<int>q1,q2;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;m=0;
		q1.clear();q2.clear();
		memset(a,0,sizeof(int)*(n+1));
		for(int i=1,x;i<=n;i++)cin>>x,a[x]++;
		for(int i=0;i<=n;i++)for(int j=a[i];j;j--)q1.push_back(i);
		cout<<a[0]<<' ';
		for(int i=1;i<=n;i++){
			while(!q1.empty()&&q1.front()<i)q2.push_back(q1.front()),q1.pop_front();
			if(q2.empty())for(;i<=n;i++)cout<<"-1 ";
			else m+=i-1-q2.back(),q2.pop_back(),cout<<m+a[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}