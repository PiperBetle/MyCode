#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<vector>
#include<stack>
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
constexpr int N=100001;
std::stack<pii>s1,s2,s3,ans;
int n,m,a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;m=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)switch(a[i]){
		case 1:
			ans.emplace(m,i);
			s1.emplace(m,i);
			m--;
			break;
		case 2:
			if(s1.empty())return cout<<"-1",0;
			ans.emplace(s1.top().fi,i);
			s2.emplace(s1.top().fi,i);
			s1.pop();
			m--;
			break;
		case 3:
			if(s1.empty()&&s2.empty()&&s3.empty())return cout<<"-1",0;
			if(!s2.empty())ans.emplace(m,s2.top().se),s2.pop();
			else if(!s3.empty())ans.emplace(m,s3.top().se),s3.pop();
			else ans.emplace(m,s1.top().se),s1.pop();
			ans.emplace(m,i);
			s3.emplace(m,i);🍥
			m--;
			break;
	}
	cout<<siz(ans)<<'\n';
	for(;!ans.empty();ans.pop())cout<<ans.top().fi<<' '<<ans.top().se<<'\n';
	return 0;
}