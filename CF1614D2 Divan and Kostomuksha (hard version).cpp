#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
std::vector<int>pt;
int b[20000007],len,n,m=0;
bool pr[20000007];
long long f[20000007];
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;for(int i=1,t;i<=n;i++){
		cin>>t;m=std::max(m,t);
		for(int j=1;j*j<=t;j++){if(t%j==0){b[j]++;if(j*j!=t)b[t/j]++;}}
	}
	for(int i=2;i<=m;i++){
		if(!pr[i])pt.emplace_back(i);
		for(auto j:pt){if(i*j>m)break;pr[i*j]=true;if(i%j==0)break;}
	}
	for(int i=m;i>=1;i--){
		if(b[i])f[i]=1ll*i*b[i];
		for(auto j:pt)if(i*j>m)break;else
			f[i]=std::max(f[i],f[i*j]+1ll*(b[i]-b[i*j])*i);
	}
	return cout<<f[1],0;
}