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
	int *operator[](int t){return data[t];}
	matrix &operator*=(matrix &t){
		matrix res;
		for(int k=1;k<=m;k++)for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%MOD;
		return *this=res;
	}
}a,t;
inline void qp(int b){for(;b;b>>=1,a*=a)if(b&1)t*=a;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	a[1][1]=a[1][m]=1;
	for(int i=1;i<m;i++)a[i+1][i]=1;
	for(int i=1;i<=m;i++)t[i][1]=1;
	qp(n);cout<<t[1][1];
	return 0;
}