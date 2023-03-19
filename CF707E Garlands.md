简要题意：在一个 $n\times m$ 的矩阵（$n,m\le2000$）中，每个点都有个灯，刚开始所有灯都是亮的，每个灯都有一个颜色（$k\le2000$）和一个权值，保证所有颜色相同的点是联通块。  
现在操作 $q$ 次
- 操作 `SWITCH x`：把所有颜色为 $x$ 的灯状态取反，开的变关，关的变开。
- 操作 `ASK x1 y1 x2 y2`：问这个子矩阵所有开着的灯的权值之和，本操作数量小于 $2000$ 次。

据说这题大暴力都能过去，但是我这个复杂度是 $\mathcal O((nm+kq_2)\log n\log m)$ （$q_2$ 表示 ASK 操作的数量）。  
发现这题有个优秀的性质：$q_2\le2000$，由于 $k\le2000$，可以对每条链对每个询问矩阵的贡献，开个 $q_2\times k$ 的 `bool` 数组去记录，再开个 $v$ 数组表示每个链有没有被关掉。每次如果是 SWITCH 就把 $v$ 数组那条链的状态取反，如果是 ASK 操作就把 $v$ 数组复制到那个 $q_2\times k$ 的数组里。  
然后就去想如何计算贡献，可以开个二维树状数组，对于每一条链上的每一个点执行一次二维树状数组上单点修，对于每次询问的贡献就相当于再这个二维树状数组上进行一次区间询问，二维树状数组差分就可以满足。注意每一条链清空贡献时不能直接 `memset`，而要添加一次负的贡献否则复杂度是错的。

代码：（删掉了用不到的缺省源，[原始代码](https://codeforces.com/contest/707/submission/181251484)）
```cpp
//不向焦虑与抑郁投降，这个世界终会有我们存在的地方。
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<tuple>
#include<random>
#define siz(x) int((x).size())
using std::cin;using std::cout;
using loli=long long;
using tiii=std::tuple<int,int,int>;
using tiiii=std::tuple<int,int,int,int>;
using bsc=std::string;
constexpr int N=2001;
int n,m,l,q;
loli ans[N];
bool v[N],w[N][N];
std::vector<tiii>a[N];
std::vector<tiiii>b;
bsc s;
loli d[N][N];
void add(int x,int y,int k){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=m;j+=j&-j)
			d[i][j]+=k;
}
loli ask(int x,int y){
	loli k=0;
	for(int i=x;i;i-=i&-i)
		for(int j=y;j;j-=j&-j)
			k+=d[i][j];
	return k;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>l;
	for(int i=1,z;i<=l;i++){
		cin>>z;a[i].resize(z);
		for(auto&[x,y,c]:a[i])cin>>x>>y>>c;
	}
	std::fill(v+1,v+1+l,true);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>s;
		if(s.front()=='A'){
			memcpy(w[siz(b)]+1,v+1,sizeof(bool)*l);
			auto&[x1,y1,x2,y2]=b.emplace_back();
			cin>>x1>>y1>>x2>>y2;
		}else{
			int p;cin>>p;
			v[p]=!v[p];
		}
	}
	for(int i=1;i<=l;i++){
		for(auto[x,y,c]:a[i])add(x,y,c);
		for(int j=0;j<siz(b);j++)
			if(auto[x1,y1,x2,y2]=b[j];w[j][i])
				ans[j]+=ask(x2,y2)-ask(x1-1,y2)-ask(x2,y1-1)+ask(x1-1,y1-1);
		for(auto[x,y,c]:a[i])add(x,y,-c);
	}
	for(int j=0;j<siz(b);j++)cout<<ans[j]<<'\n';
	return 0;
}
```