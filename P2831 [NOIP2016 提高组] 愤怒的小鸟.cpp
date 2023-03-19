#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bit>
#include<cmath>
using std::cin;using std::cout;
constexpr double eps=1e-8;
int f[1<<20|1],ln[20][20],n,m;
struct pdd{double x,y;}a[20];
inline pdd calc(pdd a,pdd b){
	double t1=-(a.y*b.x-b.y*a.x)/(b.x*b.x*a.x-a.x*a.x*b.x);
	double t2=(a.y*b.x*b.x-b.y*a.x*a.x)/(a.x*b.x*b.x-b.x*a.x*a.x);
	return pdd{t1,t2};
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int T;cin>>T;while(T--){
		memset(f,0x3f,sizeof f);memset(ln,0,sizeof ln);f[0]=0;
		cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
			if(fabs(a[i].x-a[j].x)<eps)continue;
			pdd res=calc(a[i],a[j]);
			if(res.x>-eps)continue;
			for(int k=1;k<=n;k++)if(fabs(res.x*a[k].x*a[k].x+res.y*a[k].x-a[k].y)<eps)ln[i][j]|=(1<<(k-1));
		}
		for(int i=0;i<(1<<n);i++){
			int j=std::__countr_one(i)+1;
			f[i|(1<<(j-1))]=std::min(f[i|(1<<(j-1))],f[i]+1);
			for(int k=1;k<=n;k++)f[i|ln[j][k]]=std::min(f[i|ln[j][k]],f[i]+1);
		}
		cout<<f[(1<<n)-1]<<'\n';
	}
	return 0;
}