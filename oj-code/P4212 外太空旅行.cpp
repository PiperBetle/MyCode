#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<iostream>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
bool f[57][57],b[57];
int a[57];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t,sum;
	int x,y,ans=1;
	bool flag;
	
	srand(time(NULL));
	cin>>n;
	while(cin>>x>>y)
		f[x][y]=f[y][x]=1;
	for(i=1;i<=n;i++)a[i]=i;
	for(k=1;k<=100000;k++)
	{
		random_shuffle(a+1,a+1+n);
		memset(b,0,sizeof b);
		sum=0;
		for(i=1;i<=n;i++)
		{
			flag=0;
			for(j=1;j<i;j++)
				if(b[a[j]]&&!f[a[i]][a[j]])
				{
					flag=1;
					break;
				}
			if(!flag)
			{
				b[a[i]]=1;
				sum++;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	
	return 0;
}
