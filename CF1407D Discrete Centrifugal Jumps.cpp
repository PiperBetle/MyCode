#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<stack>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using std::cin;using std::cout;
using std::max;using std::min;
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
constexpr int N=3e5+1,inf=0x3f3f3f3f;
std::stack<int>mx,mn;
int n,f[N],a[N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	memset(f+2,0x3f,sizeof(int)*(n-1));
	for(int i=1;i<=n;i++)cin>>a[i];
	mn.push(1);mx.push(1);
	for(int i=2,k;i<=n;i++){
		k=inf;
		while(!mn.empty()&&a[mn.top()]<=a[i]){
			cmin(f[i],f[mn.top()]+1);
			k=a[mn.top()];mn.pop();
		}
		if(!mn.empty()&&k!=a[i])cmin(f[i],f[mn.top()]+1);
		mn.push(i);
		k=inf;
		while(!mx.empty()&&a[mx.top()]>=a[i]){
			cmin(f[i],f[mx.top()]+1);
			k=a[mx.top()];mx.pop();
		}
		if(!mx.empty()&&k!=a[i])cmin(f[i],f[mx.top()]+1);
		mx.push(i);
	}
	cout<<f[n];
	return 0;
}