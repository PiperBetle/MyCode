#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct road{int u,v,data;bool operator<(const road &n)const{return data<n.data;}}s[1000007];
int l,f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int ans=0;
	
	cin>>n;
	for(i=0;i<1000007;i++)f[i]=i;
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		if(i<j)s[++l].u=i,s[l].v=j,cin>>s[l].data;
		else cin>>t;
	std::sort(s+1,s+1+l);
	for(i=1;;i++)
	{
		int fx=find(s[i].u),fy=find(s[i].v);
		if(fx==fy)continue;
		ans+=s[i].data;
		f[fx]=fy;
		n--;
		if(n==1)break;
	}
	cout<<ans;
	
	return 0;
}
