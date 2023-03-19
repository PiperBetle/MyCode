#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int f1[10007],f2[10007];
int a[10007],b[10007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	
	memset(f1,0x3f,sizeof f1);
	memset(f2,0x3f,sizeof f2);
	f1[0]=f2[0]=0;
	f1[1]=f2[1]=1;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=2;i<=n;i++)
	{
		memset(b,0,sizeof b);
		int cnt=0;
		for(j=i;j>=1;j--)
		{
			if(!b[a[j]])
			{
				cnt++;
				b[a[j]]=1;
			}
			if(cnt>k)break;
			f1[i]=min(f1[i],f1[j-1]+1);
			f2[i]=min(f2[i],f2[j-1]+cnt);
		}
	}
	cout<<f1[n]<<"\n"<<f2[n];
	
	return 0;
}
