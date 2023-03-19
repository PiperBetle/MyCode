#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<ctime>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[25000007];
std::string a;
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0,MOD=time(NULL);

	cin>>n;
	for(k=1;k<=n;k++)
	{
		cin>>a;
		m=0;
		for(i=a.length()-1;i>=0;i--)
			m=(m*128+a[i])%MOD;
		f[k]=m;
	}
	std::sort(f+1,f+1+n);
	for(i=1;i<n;i++)
		ans+=(f[i]!=f[i+1]);
	cout<<ans+1<<'\n';
	
	return 0;
}