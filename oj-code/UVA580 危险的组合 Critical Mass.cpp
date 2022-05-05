#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	f[3]=1;f[4]=3;
	for(i=5;i<=30;i++)f[i]=(f[i-1]<<1)+(1<<(i-4))-f[i-4];
	while(cin>>n)if(n==0)break;else cout<<f[n]<<'\n';
	
	return 0;
}
