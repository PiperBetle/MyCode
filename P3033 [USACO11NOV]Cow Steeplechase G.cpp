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
constexpr venti operator""_vt(uloli x){return venti(x);}
constexpr int N=1e5+1;
struct{int x1,x2,y1,y2,f;}a[N];
std::basic_string<int>g[N];
int n,m,ans,idx,chs[N],vis[N];
bool dfs(int u){
	for(int v:g[u]){
		if(vis[v]==idx)continue;else vis[v]=idx;
		if(!chs[v]||dfs(chs[v]))return chs[v]=u,true;
	}
	return false;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
		if(a[i].x1>a[i].x2)std::swap(a[i].x1,a[i].x2);
		if(a[i].y1>a[i].y2)std::swap(a[i].y1,a[i].y2);
		if(a[i].x1==a[i].x2)a[i].f=1,m++;else a[i].f=2;
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(a[i].f==1&&a[j].f==2){
			if(a[i].x1>=a[j].x1&&a[i].x2<=a[j].x2&&a[j].y1>=a[i].y1&&a[j].y2<=a[i].y2)
				g[i]+=j+m;
		}else if(a[i].f==2&&a[j].f==1){
			if(a[j].x1>=a[i].x1&&a[j].x2<=a[i].x2&&a[i].y1>=a[j].y1&&a[i].y2<=a[j].y2)
				g[j]+=i+m;
		}
	}
	for(int i=1;i<=n;i++)if(a[i].f==1){idx++;if(dfs(i))ans++;}
	cout<<n-ans;
	return 0;
}