#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int a[1007],f[1007];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int s,c;
	
	cin>>m>>s>>c;
	if(m>c)
	{
		cout<<c;
		return 0;
	}
	for(i=1;i<=c;i++)cin>>a[i];
	sort(a+1,a+1+c);
	for(i=1;i<c;i++)
		f[i]=a[i+1]-a[i]-1;
	sort(f+1,f+c,cmp);
	int ans=a[c]-a[1]+1;
	for(i=1;i<m&&i<c;i++)
		ans-=f[i];
	cout<<ans;
	
	return 0;
}
