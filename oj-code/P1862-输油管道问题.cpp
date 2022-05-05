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
int a[1000007];
void qs(int left,int right)
{
	int p1=left,p2=right,mid;
	mid=a[(left+right)/2];
	do
	{
		while(a[p1]<mid)p1++;
		while(a[p2]>mid)p2--;
		if(p1<=p2)swap(a[p1],a[p2]),p1++,p2--;
	}
	while(p1<=p2);
	if(left<p2)qs(left,p2);
	if(p1<right)qs(p1,right);
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,T;
	int ans=0;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>a[i];
	qs(1,n);
	if(n&1)
		m=a[(n>>1)+1];
	else
		m=(a[n>>1]+a[(n>>1)+1])>>1;
	for(i=1;i<=n;i++)
		ans+=ABS(m-a[i]);
	cout<<ans<<'\n';
	
	return 0;
}