#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
template<typename any>inline any max(any x,any y){return x>y?x:y;}
template<typename any>inline any min(any x,any y){return x<y?x:y;}
template<typename any>inline any abs(any x){return x>0?x:-x;}
struct block{int w,c;}a[10007],b[10007];
int f[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,la=0,lb=0;
	int w,c,p;

	cin>>m>>n;
	while(n--){cin>>c>>w>>p;if(p)while(p--)a[++la].w=w,a[la].c=c;else b[++lb].w=w,b[lb].c=c;}
	for(i=1;i<=la;i++)for(j=m;j>=a[i].c;j--)f[j]=max(f[j],f[j-a[i].c]+a[i].w);
	for(i=1;i<=lb;i++)for(j=b[i].c;j<=m;j++)f[j]=max(f[j],f[j-b[i].c]+b[i].w);
	for(i=0;i<m;i++)f[m]=max(f[m],f[i]);cout<<f[m];

	return 0;
}