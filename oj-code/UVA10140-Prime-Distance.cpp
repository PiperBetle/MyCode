#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int pr[1000007],pt[1000007],len;
bool b[1000007];// b[0]->left    b[right-left]->right
int a[1000007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int left,right;
	int maxn,minn,maxp,minp;
	
	for(i=0;i<1000000;i++)
		pr[i]=1;
	pr[1]=0;
	for(i=2;i<1000000;i++)
	{
		if(pr[i])
		{
			len++;
			pt[len]=i;
		}
		for(j=1;j<=len;j++)
		{
			if(i*pt[j]>=1000000)
				break;
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
				break;
		} 
	}
	while(cin>>left>>right)
	{
		memset(b,0,sizeof b);
		if(left==1)
			b[0]=1;
		for(i=1;i<=len;i++)
			for(j=left/pt[i];j<=right/pt[i];j++)
				if(j>1&&pt[i]*j>=left)
					b[pt[i]*j-left]=1;
		n=0;
		for(i=0;i<=right-left;i++)
			if(b[i]==0)
			{
				n++;
				a[n]=left+i;
			}
		if(n<=1)
		{
			puts("There are no adjacent primes.");
			continue;
		}
		maxn=-1e15;minn=1e15;
		for(i=1;i<n;i++)
		{
			if(a[i+1]-a[i]>maxn)
			{
				maxn=a[i+1]-a[i];
				maxp=i;
			}
			if(a[i+1]-a[i]<minn)
			{
				minn=a[i+1]-a[i];
				minp=i;
			}
		}
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n",a[minp],a[minp+1],a[maxp],a[maxp+1]);
	}
	
    return 0;
}