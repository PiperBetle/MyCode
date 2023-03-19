#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
struct edge{int u,v,t;}a[200007];
int f[200007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main(){
//	freopen("draw.in","r",stdin);
//	freopen("draw.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,k,n,m,T,ans;bool flag;
	cin>>T;while(T--){
		cin>>n>>m;ans=0;
		for(i=1;i<=m;i++)cin>>a[i].u>>a[i].v>>a[i].t;
		for(k=31;k>=0;k--){
			for(i=1;i<=n;i++)f[i]=i;
			for(i=1;i<=m;i++){
				if((a[i].t|ans)>=(ans+(1ll<<(k+1))))continue;
				if((a[i].t>>k)&1)continue;
				int fx=find(a[i].u),fy=find(a[i].v);
				if(fx!=fy)f[fx]=fy;
			}
			for(flag=false,i=2;i<=n;i++)if(find(1)!=find(i)){flag=true;break;}
			if(flag)ans+=1ll<<k;
		}
		cout<<ans<<'\n';
	}
	return 0;
}