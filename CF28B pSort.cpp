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
int a[1000007],f[1000007];
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void un(int x,int y){int fx=find(x),fy=find(y);if(fx!=fy)f[fx]=fy;}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	for(i=0;i<1000007;i++)f[i]=i;
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(i-t>=1)un(i-t,i);
		if(i+t<=n)un(i+t,i);
	}
	for(i=1;i<=n;i++)
		if(find(i)!=find(a[i]))return cout<<"NO",0;
	cout<<"YES";
	
	return 0;
}
