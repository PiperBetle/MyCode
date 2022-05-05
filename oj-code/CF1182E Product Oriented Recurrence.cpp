#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define MOD 1000000007
#define PHI 1000000006
using std::cin;using std::cout;
int n,m,f1,f2,f3;
struct matrix{
	int data[6][6],size;
	matrix(){}
	matrix(const int &x):size(x){memset(data,0,sizeof data);}
	void build(){for(int i=1;i<=size;i++)data[i][i]=1;} 
	int *operator[](const int &t){return data[t];}
	matrix operator*(matrix &t){
		matrix res(size);
		for(int k=1;k<=size;k++)for(int i=1;i<=size;i++)for(int j=1;j<=size;j++)
			res[i][j]=(res[i][j]+data[i][k]*t[k][j])%PHI;
		return res;
	}
}a1(3),a2(5),x(3),y(3),z(3),w(5);
inline matrix qp(matrix a,int b){matrix t(a.size);for(t.build();b;b>>=1,a=a*a)if(b&1)t=t*a;return t;}
inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>f1>>f2>>f3>>m;
	a1[1][1]=a1[1][2]=a1[1][3]=a1[2][1]=a1[3][2]=1;
	a2[1][1]=a2[1][2]=a2[1][3]=a2[1][4]=a2[1][5]=a2[2][1]=a2[3][2]=a2[4][4]=a2[4][5]=a2[5][5]=1;
	a1=qp(a1,n-3),a2=qp(a2,n-3);
	x[3][1]=y[2][1]=z[1][1]=1,w[5][1]=2;
	x=a1*x,y=a1*y,z=a1*z,w=a2*w;
	cout<<qp(f1,x[1][1])*qp(f2,y[1][1])%MOD*qp(f3,z[1][1])%MOD*qp(m,w[1][1])%MOD;
	return 0;
}