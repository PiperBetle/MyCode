#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using std::cin;using std::cout;
constexpr double exp=1e-6;
double a[107][107];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int n;cin>>n;
	for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)cin>>a[i][j];
	for(int i=1,r=1;i<=n;r=++i){
		for(int j=i+1;j<=n;j++)if(abs(a[j][i])>abs(a[j][r]))r=j;
		if(-exp<a[i][i]&&a[i][i]<exp)return cout<<"No Solution",0;
		for(int j=1;j<=n+1;j++)std::swap(a[i][j],a[r][j]);
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			double t=a[j][i]/a[i][i];
			for(int k=i;k<=n+1;k++)a[j][k]-=a[i][k]*t;
		}
	}
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(2);
	for(int i=1;i<=n;i++)cout<<a[i][n+1]/a[i][i]<<'\n';
	return 0;
}