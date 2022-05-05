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
struct road{int u,v,data;bool operator<(const road &n)const{return data<n.data;}}s[1000007];
int a[1007][1007],l,f[1000007],size[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	cin>>n;m=(n*n>>1)+(n&1);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		cin>>a[i][j];
		f[1000*i+j]=1000*i+j;size[1000*i+j]=1;
		if(i>1)s[++l].u=1000*(i-1)+j,s[l].v=1000*i+j,s[l].data=abs(a[i-1][j]-a[i][j]);
		if(j>1)s[++l].u=1000*i+(j-1),s[l].v=1000*i+j,s[l].data=abs(a[i][j-1]-a[i][j]);
	}
	std::sort(s+1,s+1+l);
	for(i=1;i<=l;i++)
	{
		int fx=find(s[i].u),fy=find(s[i].v);
//		cout<<s[i].u<<' '<<s[i].v<<' '<<s[i].data<<' '<<fx<<' '<<fy<<'\n';
		if(fx==fy)continue;
		f[fx]=fy;size[fy]+=size[fx];
		if(size[fy]>=m)return cout<<s[i].data,0;
	}

	return 0;
}
