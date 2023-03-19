#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define MOD 2017
using std::cin;using std::cout;
struct matrix{
	int data[37][37],size;
	matrix(){memset(data,0,sizeof data);}
	matrix(int size){this->size=size;for(int i=0;i<size;i++)data[i][i]=1;}
	matrix operator*(const matrix&n){
		matrix res;
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			(res.data[i][j]+=data[i][k]*n.data[k][j])%=MOD;
		return res;
	}
	matrix operator^(int p){
		matrix res(this->size),a=*this;
		for(;p;p>>=1,a=a*a)if(p&1)res=res*a;
		return res;
	}
}a;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,m,u,v,ans=0;
	cin>>a.size>>m;
	for(i=1;i<=m;i++)cin>>u>>v,a.data[u][v]=a.data[v][u];
	for(i=a.data[0][0]=1;i<=a.size;i++)a.data[i][i]=a.data[i][0]=1;
	cin>>m;a=a^m;
	for(i=0;i<=a.size;i++)ans+=a.data[1][i];
	cout<<ans%MOD;
	return 0;
}