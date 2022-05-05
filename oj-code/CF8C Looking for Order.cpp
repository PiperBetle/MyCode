#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using std::cin;using std::cout;
inline auto sqr(auto x){return x*x;}
using pii=std::pair<int,int>;
inline int dis(pii a,pii b){return sqr(a.first-b.first)+sqr(a.second-b.second);}
pii a[30];
int n,f[1<<24|1],pre[1<<24|1];
constexpr int inf=0x3f3f3f3f;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>a[0].first>>a[0].second>>n;for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	memset(f,0x3f,sizeof f);f[0]=0;
	for(int k=0;k<(1<<n);k++){
		if(f[k]==inf)continue;
		for(int i=1;i<=n;i++){
			if(k&(1<<(i-1)))continue;
			for(int j=1;j<=n;j++){
				if(k&(1<<(j-1)))continue;
				if(f[k|(1<<(i-1))|(1<<(j-1))]>f[k]+dis(a[0],a[i])+dis(a[i],a[j])+dis(a[j],a[0]))
					f[k|(1<<(i-1))|(1<<(j-1))]=f[k]+dis(a[0],a[i])+dis(a[i],a[j])+dis(a[j],a[0]),
					pre[k|(1<<(i-1))|(1<<(j-1))]=k;
			}
			break;
		}
	}
	int now=(1<<n)-1;cout<<f[(1<<n)-1]<<'\n';
	while(now){
		cout<<"0 ";
		for(int i=1;i<=n;i++)if((now^pre[now])&(1<<(i-1)))cout<<i<<' ';
		now=pre[now];
	}
	cout<<0;
	return 0;
}