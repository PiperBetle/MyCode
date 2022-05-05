#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using std::cin;using std::cout;
double a[18][18],f[1<<18|1];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	f[(1<<n)-1]=1.;
	for(int k=(1<<n)-1;k>=0;k--)if(f[k]){
		for(int i=0;i<n;i++)if((1<<i)&k)for(int j=0;j<n;j++)if((1<<j)&k){
			int cnt=__builtin_popcount(k);
			if(cnt<=1)continue;
			f[k^(1<<j)]+=f[k]*2*a[i][j]/(cnt*(cnt-1));
		}
	}
	cout<<std::setiosflags(std::ios::fixed)<<std::setprecision(6);
	for(int i=0;i<n;i++)cout<<f[1<<i]<<' ';
}