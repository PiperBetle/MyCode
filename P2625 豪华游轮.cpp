#define _USE_MATH_DEFINES
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
std::string s;
int a[1007],f[1007][1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,l=0;
	double fw=0.0,bw=0.0;

	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s>>m;
		if(s=="forward")fw+=m;
		else if(s=="backward")bw+=m;
		else if(s=="right")a[++l]=m;
		else a[++l]=-m;
	}
	f[0][0]=1;
	for(i=1;i<=l;i++)for(j=0;j<360;j++)
		f[i][j]|=f[i-1][j],
		f[i][(j+a[i]+3600)%360]|=f[i-1][j];
	int minn=7777777;
	for(j=0;j<360;j++)if(f[l][j])minn=min(minn,abs(180-j));
	double ans=fw*fw+bw*bw+2*fw*bw*cos(minn*M_PI/180.0);
	printf("%.6lf",sqrt(ans));

	return 0;
}