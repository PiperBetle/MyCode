#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 19260817
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
inline int read()
{
	int w=0;char c;
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())w=((w<<1)+(w<<3)+(c^48))%MOD;
	return w;
}
inline int qp(int a,int p,int k,int t=1){for(;p;p>>=1,a=a*a%k)if(p&1)t=t*a%k;return t;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n=read(),m=read();
	
	if(m==0)return cout<<"Angry!",0;
	int ans=n*qp(m,MOD-2,MOD);
	cout<<(ans%MOD+MOD)%MOD;
	
	return 0;
}
