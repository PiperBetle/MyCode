#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e5+1,MOD=1e9;
int n,m,k,al,fa[kN*4],se[kN*4],cnt;
bool vis[kN*4];
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){fa[x]=y;}
bool merge(int x,int y,int c){
	x=find(x),y=find(y);
	if(c){
		if(x==y)return false;
		if(x==se[y])return true;
		merge(x,se[y]),merge(se[x],y);
	}else{
		if(x==se[y])return false;
		if(x==y)return true;
		merge(x,y),merge(se[x],se[y]);
	}
	return true;
}
inline int&mul1(int&_x,int _y){return _x=int(1ll*_x*_y%MOD);}
inline int qp(int _x,int _y){int _t=1;for(;_y;_y>>=1,mul1(_x,_x))if(_y&1)mul1(_t,_x);return _t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>k;al=n+m;
	for(int i=1;i<=al;i++)fa[i]=se[i+al]=i,se[i]=fa[i+al]=i+al;
	for(int i=1,x,y,c;i<=k;i++){
		cin>>x>>y>>c;
		if((x&1)&&(y&1))c=!c;
		if(!merge(x,y+n,c))return cout<<0,0;
	}
	vis[find(1)]=vis[se[find(1)]]=true;
	for(int i=2;i<=al;i++){
		if(!vis[find(i)])cnt++;
		vis[find(i)]=vis[se[find(i)]]=true;
	}
	cout<<qp(2,cnt);
	return 0;
}