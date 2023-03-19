#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
int f[200007],sum[200007],size[200007];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	f[fy]=fx;
	size[fx]+=size[fy];
	sum[fx]+=sum[fy];
}
void remove(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)return;
	f[x]=fy;
	size[fx]--;
	size[fy]++;
	sum[fx]-=x;
	sum[fy]+=x;
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int t,x,y;
	
	while(cin>>n>>m)
	{
		for(i=n+1;i<=(n<<1);i++)f[i]=f[i-n]=i,size[i]=1,sum[i]=i-n;
		while(m--)
		{
			cin>>t>>x;
			if(t==1){cin>>y;merge(x,y);}
			if(t==2){cin>>y;remove(x,y);}
			if(t==3)cout<<size[find(x)]<<' '<<sum[find(x)]<<'\n';
		}
	}

	return 0;
}