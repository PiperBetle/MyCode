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
constexpr int N=100001;
int n,m;
bool a[N];
struct dsu{
	int fa[N];
	dsu(){for(int i=1;i<N;i++)fa[i]=i;}
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){if((x=find(x))!=(y=find(y)))fa[x]=y;}
	bool query(int x,int y){return find(x)==find(y);}
}x[30],y[30];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		for(int j=0;j<30;j++)if(w>>j&1)x[j].merge(u,v);
		if(~w&1)a[u]=a[v]=1;
	}
	for(int i=0;i<30;i++){
		y[i]=x[i];
		for(int j=1;j<=n;j++)if(a[j])y[i].merge(0,j);
	}
	cin>>m;
	for(int u,v;m--;){
		cin>>u>>v;
		cout<<[&]{
			for(int i=0;i<30;i++)if(x[i].query(u,v))return '0';
			for(int i=1;i<30;i++)if(y[i].query(u,0))return '1';
			return '2';
		}()<<'\n';
	}
	return 0;
}