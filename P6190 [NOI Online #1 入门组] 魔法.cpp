#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
constexpr int inf=0x3f3f3f3f3f3f3f3f;
int n,m,r,dis[107][107];
struct edge{int u,v,t;}e[2507];
struct matrix{
	int data[107][107],size;
	matrix(){}
	matrix(const int &x):size(x){memset(data,0,sizeof data);}
	int *operator[](const int &t){return data[t];}
	matrix operator*(matrix &t){
		matrix res(size);
		for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)res[i][j]=inf;
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]=std::min(res[i][j],data[i][k]+t[k][j]);
		return res;
	}
	matrix &operator^=(int t){
		matrix res(size);
		for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)res[i][j]=dis[i][j];
		for(;t;t>>=1,*this=*this**this)if(t&1)res=res**this;
		return *this=res;
	}
}a;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m>>r;a.size=n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dis[i][j]=inf;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].t,dis[e[i].u][e[i].v]=e[i].t;
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	if(!r)return cout<<dis[1][n],0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=dis[i][j];
	for(int k=1;k<=m;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		a[i][j]=std::min(a[i][j],dis[i][e[k].u]+dis[e[k].v][j]-e[k].t);
	cout<<(a^=r)[1][n];
	return 0;
}