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
constexpr int kN=3001,dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
int f[kN*kN*2],n,m,q,ans;
bool vis[kN][2*kN];
inline int p(int x,int y){return 2*(x-1)*m+y;}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline int find(int x,int y){return find(p(x,y));}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))f[x]=y;}
inline void merge(int x1,int y1,int x2,int y2){merge(p(x1,y1),p(x2,y2));}
bool check(int &x,int &y){
	if(y==0)y=m*2;
	if(y==2*m+1)y=1;
	return 1<=x&&x<=n&&vis[x][y];
}
bool can_del(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(!check(nx,ny))continue;
		for(int j=0;j<8;j++){
			int lx=x+dx[j],ly=y+m+dy[j];
			if(!check(lx,ly))continue;
			if(find(nx,ny)==find(lx,ly))return false;
		}
	}
	return true;
}
void del(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(check(nx,ny))merge(x,y,nx,ny);
		int lx=x+dx[i],ly=y+m+dy[i];
		if(check(lx,ly))merge(x,y+m,lx,ly);
	}
	vis[x][y]=vis[x][y+m]=true;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>q;
	if(m==1)return cout<<0,0;
	for(int i=1;i<=n;i++)for(int j=1;j<=2*m;j++)f[p(i,j)]=p(i,j);
	for(int x,y;q--;){cin>>x>>y;if(can_del(x,y))del(x,y),ans++;}
	cout<<ans;
	return 0;
}