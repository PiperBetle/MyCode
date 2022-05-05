#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
bool pr[1000007];
int pt[1000007],len=0;
int sum[1000007],a[1000007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	
	for(i=5;i<=1000001;i+=4)
	{
		if(pr[i])
			continue;
		pt[++len]=i;
		for(j=i*5;j<=1000001;j+=i*4)
			pr[j]=1;
	}
	for(i=1;i<=len;i++)
		for(j=1;j<=i&&pt[i]*pt[j]<=1000001;j++)
			a[pt[i]*pt[j]]=1;
	for(i=1;i<=1000001;i++)
		sum[i]=sum[i-1]+a[i];
	while(cin>>n)
	{
		if(n==0)
			return 0;
		cout<<n<<' '<<sum[n]<<'\n';
	}
	
	return 0;
}