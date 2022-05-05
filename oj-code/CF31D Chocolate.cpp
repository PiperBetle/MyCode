#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define int long long
using std::cin;using std::cout;
bool a[1007][1007];
int f[2000007],size[2000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void un(int x1,int y1,int x2,int y2)
{
	int fx=find(x1*1000+y1),
		fy=find(x2*1000+y2);
	if(fx!=fy)f[fy]=fx,size[fx]+=size[fy];
}
std::vector<int>s;
signed main()
{
	// freopen("chocolate.in","r",stdin);
	// freopen("chocolate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans=0;
	int x1,y1,x2,y2;
	
	for(i=0;i<2000007;i++)f[i]=i,size[i]=0;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)size[((i<<1)-1)*1000+(j<<1)-1]=1;
	while(k--)
	{
		cin>>x1>>y1>>x2>>y2;
		x1<<=1;x2<<=1;y1<<=1;y2<<=1;
		if(x1==x2)for(i=y1;i<=y2;i++)a[x1][i]=1;
		if(y1==y2)for(i=x1;i<=x2;i++)a[i][y1]=1;
	}
	for(i=0;i<=(n<<1);i++)a[i][0]=a[i][m<<1]=1;
	for(i=0;i<=(m<<1);i++)a[0][i]=a[n<<1][i]=1;
	for(i=0;i<=(n<<1);i++)for(j=0;j<=(m<<1);j++)
	{
		if(a[i][j]==1)continue;
		if(a[i-1][j]==0)un(i,j,i-1,j);
		if(a[i][j-1]==0)un(i,j,i,j-1);
		if(a[i+1][j]==0)un(i,j,i+1,j);
		if(a[i][j+1]==0)un(i,j,i,j+1);
	}
	for(i=0;i<=(n<<1);i++)for(j=0;j<=(m<<1);j++)if(!a[i][j]&&find(1000*i+j)==1000*i+j)s.emplace_back(size[1000*i+j]);
	std::sort(s.begin(),s.end());
	for(auto it:s)cout<<it<<' ';
	
	return 0;
}