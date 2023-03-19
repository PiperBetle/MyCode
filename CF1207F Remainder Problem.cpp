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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=500001,M=708;
int q;
loli a[N],b[M][M];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>q;for(int x,y;q--;){
		if(cin>>x,x==1){
			cin>>x>>y;
			for(int i=1;i<M;i++)b[i][x%i]+=y;
			a[x]+=y;
		}else{
			cin>>x>>y;
			if(x<M)cout<<b[x][y]<<'\n';
			else cout<<[&]{
				loli sum=0;
				for(int i=y;i<N;i+=x)sum+=a[i];
				return sum;
			}()<<'\n';
		}
	}
	return 0;
}