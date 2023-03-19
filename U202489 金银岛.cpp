#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using std::cin;using std::cout;
inline int max(int x,int y){return x>y?x:y;}
inline int min(int x,int y){return x<y?x:y;}
inline int abs(int x){return x>0?x:-x;}
struct gold{double n,v;bool operator<(const gold &x)const{return v/n>x.v/x.n;}}a[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;

	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		double ans=0.0;
		for(i=1;i<=n;i++)cin>>a[i].n>>a[i].v;
		std::sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
			if(m>=a[i].n)ans+=a[i].v,m-=a[i].n;
			else{ans+=a[i].v/a[i].n*m;break;}
		printf("%.2f\n",ans);
	}

	return 0;
}