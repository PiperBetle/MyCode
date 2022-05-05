#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
int c[5],d[5],n,f[100007];
template<typename any>inline any calc(any x){return c[x]*(d[x]+1);}
template<typename any,typename ...args>inline any calc(any x,args... y){return calc(x)+calc(y...);}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c[1]>>c[2]>>c[3]>>c[4];
	for(int i=f[0]=1;i<=4;i++)for(int j=c[i];j<=100000;j++)f[j]+=f[j-c[i]];
	int T;cin>>T;while(T--){
		cin>>d[1]>>d[2]>>d[3]>>d[4]>>n;
		int ans=f[n];
		if(n>=calc(1))ans-=f[n-calc(1)];
		if(n>=calc(2))ans-=f[n-calc(2)];
		if(n>=calc(3))ans-=f[n-calc(3)];
		if(n>=calc(4))ans-=f[n-calc(4)];
		if(n>=calc(1,2))ans+=f[n-calc(1,2)];
		if(n>=calc(1,3))ans+=f[n-calc(1,3)];
		if(n>=calc(1,4))ans+=f[n-calc(1,4)];
		if(n>=calc(2,3))ans+=f[n-calc(2,3)];
		if(n>=calc(2,4))ans+=f[n-calc(2,4)];
		if(n>=calc(3,4))ans+=f[n-calc(3,4)];
		if(n>=calc(1,2,3))ans-=f[n-calc(1,2,3)];
		if(n>=calc(1,2,4))ans-=f[n-calc(1,2,4)];
		if(n>=calc(1,3,4))ans-=f[n-calc(1,3,4)];
		if(n>=calc(2,3,4))ans-=f[n-calc(2,3,4)];
		if(n>=calc(1,2,3,4))ans+=f[n-calc(1,2,3,4)];
		cout<<ans<<'\n';
	}
	return 0;
}