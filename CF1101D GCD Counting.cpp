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
constexpr int N=2e5+1;
std::basic_string<int>pt,d[N],g[N],f[N];
int n,mif[N],ans;
bool pr[N];
void dfs(int u,int fa){
	for(int v:g[u])if(v!=fa){
		dfs(v,u);
		for(int j=0,k=0;j<siz(d[u]);j++){
			while(k<siz(d[v])&&d[v][k]<d[u][j])k++;
			if(k<siz(d[v])&&d[v][k]==d[u][j]){
				ans=std::max(ans,f[v][k]+f[u][j]);
				f[u][j]=std::max(f[u][j],f[v][k]+1);
			}
		}
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	for(int i=2;i<N;i++){
		if(!pr[i])pt+=i,mif[i]=i;
		for(int j:pt){
			if(i*j>=N)break;
			pr[i*j]=true,mif[i*j]=j;
			if(i%j==0)break;
		}
	}
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;if(x!=1)ans=1;
		for(int p=mif[x];x>1;p=mif[x]){
			while(x%p==0)x/=p;
			d[i]+=p;
		}
		f[i].resize(siz(d[i]));
		std::fill(all(f[i]),1);
	}
	for(int i=1,u,v;i<n;i++)cin>>u>>v,g[u]+=v,g[v]+=u;
	dfs(1,0);
	cout<<ans;
	return 0;
}