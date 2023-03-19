#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cmath>
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
constexpr double eps=1e-6;
constexpr int N=102;
int n;
double a[N][N];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
	cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)cin>>a[i][j];
	for(int i=1,r=1;i<=n;r=++i){
		for(int j=i+1;j<=n;j++)if(abs(a[j][i])>abs(a[r][i]))r=j;
		if(r!=i)for(int j=1;j<=n+1;j++)std::swap(a[i][j],a[r][j]);
		if(fabs(a[i][i])<eps)return cout<<"No Solution",0;
		for(int j=i+1;j<=n+1;j++)a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++)if(i!=j)for(int k=i+1;k<=n+1;k++)a[j][k]-=a[i][k]*a[j][i];
	}
	for(int i=1;i<=n;i++)cout<<a[i][n+1]<<'\n';
	return 0;
}