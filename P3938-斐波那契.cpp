#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define double long double
inline int MAX(int x,int y){return x>y?x:y;}
inline int MIN(int x,int y){return x<y?x:y;}
inline int ABS(int x){return x>0?x:-x;}
using namespace std;
int a[107];
int find(int n,int m)
{
	if(n<m)swap(n,m);
	if(n==m)return n;
	int *p=lower_bound(a,a+70,n)-1;
    return find(m,n-*p);
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0;
	
	a[0]=a[1]=1;
	for(i=2;i<=70;i++)
		a[i]=a[i-1]+a[i-2];
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cout<<find(n,m)<<'\n';
	}
	
	return 0;
}