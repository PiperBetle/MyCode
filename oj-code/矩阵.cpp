#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
int n,m;
struct matrix{
	int data[107][107];
	matrix(){memset(data,0,sizeof data);}
	matrix(int x){for(int i=0;i<107;i++)data[i][i]=x;}
	int *operator[](int t){return data[t];}
	void read(){for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>data[i][j];}
	void write(){for(int i=1;i<=n;i++,cout<<'\n')for(int j=1;j<=n;j++)cout<<data[i][j]<<' ';}
	matrix operator*(matrix &t){
		matrix res;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%MOD;
		return res;
	}
	matrix &operator*=(matrix &t){
		matrix res;
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%MOD;
		return *this=res;
	}
}a,t;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int m;cin>>n>>m;
	a[1][1]=a[1][m]=1;
	for(int i=1;i<m;i++)a[i+1][i]=1;
	for(int i=1;i<=m;i++)t[i][1]=1;
	for(;n;n>>=1,a*=a)if(n&1)t*=a;
	cout<<t[1][1];
	return 0;
}