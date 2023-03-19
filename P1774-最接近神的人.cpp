#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[500007],t[500007];
long long ans=0;
void ms(int l,int r)
{
	if(l==r)return;
	int m=(l+r)/2;
	ms(l,m);
	ms(m+1,r);
	int p=l,i=l,j=m+1;
	while(i<=m&&j<=r)
	{
		if(a[i]>a[j])
		{
			ans=ans+m-i+1;
			t[p++]=a[j++];
		}
		else t[p++]=a[i++];
	}
	while(i<=m)t[p++]=a[i++];
	while(j<=r)t[p++]=a[j++];
	for(i=l;i<=r;i++)a[i]=t[i];
}
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	// std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
        scanf("%lld",a+i);
	ms(1,n);
	printf("%lld",ans);
	
	return 0;
}
