#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
int n,m;
struct floyd{
	int data[207][207];
	floyd&operator*=(const floyd&t2){
		floyd t1=*this;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			data[i][j]=std::min(data[i][j],t1.data[i][k]+t2.data[k][j]);
		return *this;
	}
	floyd operator^(int p){
		floyd t1=*this,t2;
		memset(t2.data,0x3f,sizeof t2.data);
		for(;p;p>>=1,t1*=t1)if(p&1)t2*=t1;
		return t2;
	}
}g,ans;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,start,end;
	cin>>n>>m>>start>>end;
	memset(g.data,0x3f,sizeof g.data);
	while(m--){
		cin>>t>>u>>v;
		
	}
	return 0;
}