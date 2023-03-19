#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
bool pr[10000007];
int pt[5000007],len,phi[10000007];
inline int qp(int a,int b,int p,int t=1){for(;b;b>>=1,a=a*a%p)if(b&1)t=t*a%p;return t;}
int solve(int p){return p==1?0:qp(2,solve(phi[p])+phi[p],p);}
signed main(){
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,T,t;
	for(pr[1]=true,phi[1]=1,i=2;i<=10000000;i++){
		if(!pr[i])pt[++len]=i,phi[i]=i-1;
		for(j=1;j<=len&&i*pt[j]<=10000000;j++){
			pr[i*pt[j]]=true;
			if(i%pt[j]==0){phi[i*pt[j]]=phi[i]*pt[j];break;}
			else phi[i*pt[j]]=phi[i]*(pt[j]-1);
		}
	}
	cin>>T;while(T--)cin>>t,cout<<solve(t)<<'\n';
	return 0;
}