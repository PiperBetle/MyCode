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
char a[207];
int f[207][27][27][27];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int A,B,C;

	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	memset(f,0x3f,sizeof f);
	f[0][0][0][0]=0;
	for(i=0;i<=n;i++)
		for(A=0;A<=10;A++)
			for(B=0;B<=10;B++)
				for(C=0;C<=10;C++)
				{
					if(A+B+C>10)
						break;
					if(a[i]=='A'&&A)
						f[i][A][B][C]=f[i-1][A-1][B][C];
					if(a[i]=='B'&&B)
						f[i][A][B][C]=f[i-1][A][B-1][C];
					if(a[i]=='C'&&C)
						f[i][A][B][C]=f[i-1][A][B][C-1];
					f[i][0][B][C]=min(f[i][0][B][C],f[i][A][B][C]+1);
					f[i][A][0][C]=min(f[i][A][0][C],f[i][A][B][C]+1);
					f[i][A][B][0]=min(f[i][A][B][0],f[i][A][B][C]+1);
				}
	cout<<f[n][0][0][0]<<'\n';

	return 0;
}