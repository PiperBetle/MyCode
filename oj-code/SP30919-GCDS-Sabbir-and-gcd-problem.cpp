#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int pt[10000007],sm[10000007]={0,1},len;
bool b[10000007],pr[10000007];
signed main()
{
	int i,j,k;
	int n,m,T;
	int a;

	for(i=2;i<=10000000;i++)
	{
		if(!pr[i])
		{
			pt[++len]=i;
			sm[i]=i;
		}
		for(j=1;j<=len&&i*pt[j]<=10000000;j++)
		{
			pr[i*pt[j]]=1;
			sm[i*pt[j]]=pt[j];
			if(i%pt[j]==0)break;
		}
	}
	// for (i=1;i<=10000000;i++)
	// 	if (sm[i]==0)
	// 	{	cout<<"sm!"<<i<<endl;
	// 		return 0;
	// 	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		memset(b,0,sizeof b);
		while(n--)
		{
			scanf("%lld",&a);
			while(a>1)
			{
				b[sm[a]]=1;
				a/=sm[a];
			}
		}
		for(i=1;i<=len;i++)
			if(!b[pt[i]])
			{
				printf("%lld\n",pt[i]);
				break;
			}
	}
	
	return 0;
}