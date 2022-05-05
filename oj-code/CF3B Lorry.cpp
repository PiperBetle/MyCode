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
int a[100007],b[100007],l1,l2;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,v,t;
	
	cin>>n>>v;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1)cin>>a[++l1];
		else cin>>b[++l2];
	}
	std::sort(a+1,a+l1+1,std::greater<int>());std::sort(b+1,b+l2+1,std::greater<int>());
	
	return 0;
}
