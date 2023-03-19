题意：平面上有 $n$ 个地雷，第 $i$ 颗地雷在 $(x_i,y_i)$，会在第 $t_i$ 秒自动爆炸，在一个地雷爆炸后，在这个雷正十字形内距离小于 $k$ 的雷也会爆炸。你可以在第 $i$ 秒手动引爆一个雷，问要让所有雷爆炸要多久？

若 $a$ 能引爆 $b$，$b$ 也一定能引爆 $a$，可以用并查集把所有能相互引爆的雷合并起来，合并这个过程可以对 $x,y$ 坐标进行排序，合并 $x$ 或 $y$ 相同的，另一位差值小于 $k$ 的雷。接下来就可以直接引爆最后爆炸的雷了！贪心处理。
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#define siz(x) int(std::size(x))
#define cauto const auto
#define all(x) std::begin(x),std::end(x)
using std::cin;using std::cout;
template<typename any>inline void cmin(any &x,const any &y){if(y<x)x=y;}
using bsi=std::basic_string<int>;
constexpr int N=2e5+1,inf=0x3f3f3f3f;
int n,m,fa[N],w[N],ans;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y;}
struct{int x,y,w,id;}a[N];
bsi v;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	int T;cin>>T;while(T--){
		cin>>n>>m;v.clear();
		for(int i=1;i<=n;i++)fa[i]=i,cin>>a[i].x>>a[i].y>>a[i].w,a[i].id=i;
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.x==p2.x?p1.y<p2.y:p1.x<p2.x;});
		for(int i=2;i<=n;i++)if(a[i-1].x==a[i].x&&a[i-1].y+m>=a[i].y)merge(a[i-1].id,a[i].id);
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.y==p2.y?p1.x<p2.x:p1.y<p2.y;});
		for(int i=2;i<=n;i++)if(a[i-1].y==a[i].y&&a[i-1].x+m>=a[i].x)merge(a[i-1].id,a[i].id);
		std::sort(a+1,a+1+n,[](cauto&p1,cauto&p2){return p1.id<p2.id;});
		memset(w+1,0x3f,sizeof(int)*n);
		for(int i=1;i<=n;i++)cmin(w[find(i)],a[i].w);
		for(int i=1;i<=n;i++)if(find(i)==i)v+=w[i];
		sort(all(v),std::greater<>());
		v+=-inf;for(ans=0;ans<siz(v);ans++)if(v[ans+1]<=ans)break;
		cout<<ans<<'\n';
	}
	return 0;
}
```