#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
auto MAX(auto x,auto y){return x>y?x:y;}
auto MIN(auto x,auto y){return x<y?x:y;}
double f[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,t;
	
	cin>>n;
	f[n]=1.00000000;
	f[n-1]=0.00000000;
	for(i=n-2;i>=0;i--)
		f[i]=0.50000000*f[i+1]+0.50000000*f[i+2];
	printf("%.8f\n%.8f",1-f[0],f[0]); 
	
    return 0;
}
