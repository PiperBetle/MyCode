#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
bool pr[1000007];
int pt[1000007],len=0;
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,T;
	int left,right;
	int sum,ans;
	
	for(i=0;i<1000000;i++)
		pr[i]=1;
	pr[1]=0;
	for(i=2;i<1000000;i++)
	{
		if(pr[i])
			pt[++len]=i;
		for(j=1;j<=len&&i*pt[j]<1000000;j++)
		{
			pr[i*pt[j]]=0;
			if(i%pt[j]==0)
				break;
		}
	}
	//线性筛
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&left,&right);
		ans=0;
		for(i=2;i*i<=right;i++)//枚举底数
		{
			if(!pr[i])
				continue;
			sum=i;
			for(;;)//枚举幂
			{
				sum*=i;
				if(sum>=right)
					break;
				if(sum>=left)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}