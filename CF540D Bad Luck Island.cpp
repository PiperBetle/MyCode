#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using std::cin;using std::cout;
double f[107][107][107],r,s,p;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int a,b,c;cin>>a>>b>>c;f[a][b][c]=1.;
	for(int i=a;i>=0;i--)for(int j=b;j>=0;j--)for(int k=c;k>=0;k--){
		double tot=i*j+j*k+i*k;
		if(i&&k)f[i-1][j][k]+=f[i][j][k]*i*k/tot;
		if(i&&j)f[i][j-1][k]+=f[i][j][k]*i*j/tot;
		if(j&&k)f[i][j][k-1]+=f[i][j][k]*j*k/tot;
		if(i&&!j&&!k)r+=f[i][j][k];
		if(!i&&j&&!k)s+=f[i][j][k];
		if(!i&&!j&&k)p+=f[i][j][k];
	}
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(12)<<r<<' '<<s<<' '<<p;
	return 0;
}