#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<vector>
#define siz(x) int((x).size())
#define cauto const auto
#define all(x) (x).begin(),(x).end()
using std::cin;using std::cout;
using loli=long long;
using venti=__int128_t;
using pii=std::pair<int,int>;
constexpr int kN=1e7+1,kM=1e2+1;
int n,m,mat[kN],ans;
std::basic_string<int>pt,odd,eve;
std::vector<int>g[kN];
bool pr[kN],b[kN],vis[kN];
bool dfs(int u){
	for(int v:g[u])if(!vis[v]){
		vis[v]=true;
		if(!mat[v]||dfs(mat[v]))return mat[v]=u,true;
	}
	return false;
}
signed main(){
//	freopen("India.in","r",stdin);
//	freopen("India.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	pr[1]=true;
for(int i=2;i<kN;i++){
		if(!pr[i])pt+=i;
		for(int j:pt){
			if(i*j>=kN)break;
			pr[i*j]=true;
			if(i%j==0)break;
		}
	}
	cin>>n;
	for(int i=1,x;i<=n;i++)cin>>x,b[x]=true,m=std::max(m,x+1);
	for(int i=m;i>=1;i--)b[i]^=b[i-1];
	for(int i=1;i<=m;i++)if(b[i])(i&1?odd:eve)+=i;
	for(int i:odd)for(int j:eve)if(!pr[abs(i-j)])g[i].push_back(j);
	for(int i:odd)if(!mat[i]){for(int j:eve)vis[j]=0;ans+=dfs(i);}
	cout<<ans+(siz(odd)-ans)/2*2+(siz(eve)-ans)/2*2+(siz(odd)-ans)%2*3;
	return 0;
}