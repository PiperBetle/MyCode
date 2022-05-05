#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
using std::min;
int a[207][207],f[207][207],pos[207][207];
std::vector<int>p;
void dfs(int u,int v){
	if(!pos[u][v])return;
	dfs(u,pos[u][v]);
	p.push_back(pos[u][v]);
	dfs(pos[u][v],v);
}
int main(){
	std::ios::sync_with_stdio(false);
	int i,j,k,n,m,ans=0x3f3f3f3f,u,v,t;
	cin>>n>>m;
	memset(f,0x3f,sizeof f);
	for(i=1;i<=n;i++)f[i][i]=0;
	for(i=1;i<=m;i++)cin>>u>>v>>t,a[u][v]=a[v][u]=f[u][v]=f[v][u]=min(f[u][v],t);
	for(k=1;k<=n;k++){
		for(i=1;i<k;i++)for(j=i+1;j<k;j++)if(f[i][j]+a[i][k]+a[k][j]<ans&&a[i][k]>0&&a[k][j]>0)
			ans=f[i][j]+a[i][k]+a[k][j],
			p.clear(),p.emplace_back(i),dfs(i,j),p.emplace_back(j),p.emplace_back(k);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(f[i][k]+f[k][j]<f[i][j])
			f[i][j]=f[i][k]+f[k][j],pos[i][j]=k;
	}
	if(ans==0x3f3f3f3f)cout<<"No solution.";
	else for(auto it:p)cout<<it<<' ';
	return 0;
}