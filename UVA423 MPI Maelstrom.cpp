#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[107][107];
std::string s;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,ans=0;
	
	memset(f,0x3f,sizeof f);
	for(i=0;i<107;i++)f[i][i]=0;
	cin>>n;
	for(i=2;i<=n;i++)for(j=1;j<i;j++)
		{cin>>s;if(s!="x")f[i][j]=f[j][i]=std::atoi(s.c_str());}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(i=1;i<=n;i++)ans=max(ans,f[1][i]);
	cout<<ans;

	return 0;
}
