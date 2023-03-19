#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<iomanip>
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
constexpr int N=1001;
double a[N][N],b[N],f[N];
int n,m,x,y;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m>>x>>y;
	for(int k=n-1;k>=x;k--){
		a[1][1]=-2./3;a[1][2]=1./3;b[1]=-f[1]/3-1;
		a[m][m-1]=1./3;a[m][m]=-2./3;b[m]=-f[m]/3-1;
		for(int i=2;i<m;i++){
			a[i][i-1]=a[i][i+1]=1./4;
			a[i][i]=-3./4;
			b[i]=-f[i]/4-1;
		}
		if(m==1)a[1][1]=-1./2,b[1]=-f[1]/2-1;
		for(int i=1;i<m;i++){
			double t=a[i+1][i]/a[i][i];
			a[i+1][i]-=t*a[i][i];
			a[i+1][i+1]-=t*a[i][i+1];
			b[i+1]-=t*b[i];
		}
		f[m]=b[m]/a[m][m];
		for(int i=m-1;i;i--)f[i]=(b[i]-f[i+1]*a[i][i+1])/a[i][i];
	}
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(5)<<f[y];
	return 0;
}