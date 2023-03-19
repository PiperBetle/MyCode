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
constexpr int N=2*5e5+1;
int n,a[N],b[N],c[N];
bsc s;
bool check(int l,int r,int L,int R){
	s.resize(2*n-2);
	for(int i=1;i<n;i++){
#define d1 (r-l+1)
#define d2 (R-L+1)
		if(d1>1&&a[l]==a[r])l++,r--,s[i-1]='L',s[n*2-2-i]='L';
		else if(d1&&d2&&a[l]==a[L])l++,L++,s[i-1]='L',s[n*2-2-i]='R';
		else if(d1&&d2&&a[r]==a[R])r--,R--,s[i-1]='R',s[n*2-2-i]='L';
		else if(d2>1&&a[L]==a[R])L++,R--,s[i-1]='R',s[n*2-2-i]='R';
		else return false;
#undef d1
#undef d2
	}
	return true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			if(b[a[i]]){
				c[i]=b[a[i]];
				c[b[a[i]]]=i;
				b[a[i]]=0;
			}else b[a[i]]=i;
		}
		bool f=check(2,c[1]-1,c[1]+1,2*n);
		if(f){cout<<'L'<<s<<"L\n";continue;}
		f=check(1,c[2*n]-1,c[2*n]+1,2*n-1);
		if(f){cout<<'R'<<s<<"L\n";continue;}
		cout<<"-1\n";
	}
	return 0;
}