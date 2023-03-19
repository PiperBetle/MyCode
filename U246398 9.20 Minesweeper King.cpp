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
using loli=long long;
using uloli=unsigned long long;
using lodb=long double;
using venti=__int128_t;
using pii=std::pair<int,int>;
using inlsi=const std::initializer_list<int>&;
using bsi=std::basic_string<int>;
constexpr venti operator""_vt(uloli x){return venti(x);}
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
template<typename any>inline void cmax(any &x,const any &y){if(x<y)x=y;}
template<typename any,typename...args>inline void cmax(any &x,const any &y,const args &...z){cmax(x,y);cmax(x,z...);}
template<typename any,typename...args>inline void cmin(any &x,const any &y,const args &...z){cmin(x,y);cmin(x,z...);}
#define count __builtin_popcount
const int N=21,M=9,K=51;
int n,m,w,f[2][1<<M][K],g[N],ans;
char ch;
inline int cnt1(int x,int S){
	int res=0;
	for(int i=0;i<m;i++)
		if(g[x]>>i&1||S>>i&1);
		else res+=(i?S>>(i-1)&1:0)+(i!=m-1?S>>(i+1)&1:0);
	return res;
}
inline int cnt2(int x,int X,int Y){
	int res=0;
	for(int i=0;i<m;i++)
		if(g[x]>>i&1||Y>>i&1);
		else res+=(i?X>>(i-1)&1:0)+(X>>i&1)+(i!=m-1?X>>(i+1)&1:0);
	for(int i=0;i<m;i++)
		if(g[x-1]>>i&1||X>>i&1);
		else res+=(i?Y>>(i-1)&1:0)+(Y>>i&1)+(i!=m-1?Y>>(i+1)&1:0);
	return res;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)cin>>ch,ch=='#'&&(g[i]|=1<<j);
	memset(f[1],-0x3f,sizeof(f[1]));
	for(int i=0;i<1<<m;i++)if(!(i&g[1])&&count(i)<=w)f[1][i][count(i)]=cnt1(1,i);
	for(int I=2,i=0,x,y;I<=n;I++,i^=1){
		memset(f[i],-0x3f,sizeof(f[i]));
		for(int j=g[I];;(--j)&=g[I]){
			for(int k=g[I-1];;(--k)&=g[I-1]){
				x=cnt2(I,k,j),y=cnt1(I,j);
				for(int l=w,lim=count(j);l>=lim;l--)cmax(f[i][j][l],f[i^1][k][l-lim]+x+y);
				if(!k)break;
			}
			if(!j)break;
		}
	}
	for(int i=0;i<1<<m;i++)cmax(ans,f[n&1][i][w]);
	cout<<ans<<'\n';
	return 0;
}