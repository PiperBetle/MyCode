#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define MOD 1000000007
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[1000007],sum[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int l,r;
	
	cin>>T>>k;
	f[0]=1;
	for(i=1;i<=100000;i++)
	{
		f[i]=f[i-1];
		if(i>=k)f[i]=(f[i]+f[i-k])%MOD;
		sum[i]=(sum[i-1]+f[i])%MOD;
	}
	while(T--)
	{
		cin>>l>>r;
		cout<<(sum[r]-sum[l-1]+MOD)%MOD<<'\n';
	}
	
	return 0;
}
