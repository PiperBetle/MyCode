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
int a[10000007];
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
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,last;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	qs(1,n);
	last=1;
	for(i=1;i<=n;i++)
		if(a[i]!=a[i+1])
		{
			printf("%d %d\n",a[i],i-last+1);
			last=i+1;
		}
	
    return 0;
}