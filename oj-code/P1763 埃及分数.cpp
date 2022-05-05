#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
int maxdep,ans[10000007],b[10000007];
inline int gcd(int a, int b)
{
	if(!a)return b;
	if(!b)return a;
	signed t=__builtin_ctz(a|b);
	a>>=__builtin_ctz(a);
	do{
		b>>=__builtin_ctz(b);
		if(a>b)std::swap(a,b);
		b-=a;
	}while(b);
	return a<<t;
}
bool dfs(int now,int x,int y){
	if(now>maxdep){
		if(x)return false;
		if(ans[maxdep]>b[maxdep])for(int i=1;i<=maxdep;i++)ans[i]=b[i];
		return true;
	}
	bool flag=false;
	for(int i=std::max((int)ceil(1.*y/x),b[now-1]+1);i<=ceil(y/x)*(maxdep-now+1);i++){
		b[now]=i;
		int tx=x*i-y,ty=y*i,g=gcd(tx,ty);
		tx/=g;ty/=g;
		if(dfs(now+1,tx,ty))flag=true;
	}
	return flag;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,n,m;
	cin>>n>>m;
	for(maxdep=1;;maxdep++){
		ans[maxdep]=0x3f3f3f3f;
		if(dfs(1,n,m))break;
	}
	for(i=1;i<=maxdep;i++)cout<<ans[i]<<' ';	 
	return 0;
}