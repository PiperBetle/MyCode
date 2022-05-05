#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
int a[1007][1007];
int max_a[1007][1007],min_a[1007][1007];
int max_f[1007][1007],min_f[1007][1007];
int q[10007];
signed main()
{
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int x,y;
	int left,right;
	
	cin>>n>>m>>k;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			cin>>a[i][j];

	for(i=1;i<=n;i++)
	{
		memset(q,0,sizeof q);
		left=right=q[1]=1;
		for(j=2;j<=m;j++)
		{
			while(left<=right&&j-q[left]>=k)
				left++;
			while(left<=right&&a[i][q[right]]>a[i][j])
				right--;
			q[++right]=j;
			if(j>=k)max_f[i][j-k+1]=a[i][q[right]];
		}
	}
	for(i=1;i<=m-k+1;i++)
	{
		memset(q,0,sizeof q);
		left=right=q[1]=1;
		for(j=2;j<=m;j++)
		{
			while(left<=right&&j-q[left]>=k)
				left++;
			while(left<=right&&max_f[i][q[right]]>max_f[i][j])
				right--;
			q[++right]=j;
			if(j>=k)max_a[i][j-k+1]=max_f[i][q[right]];
		}
	}

	for(i=1;i<=n;i++)
	{
		memset(q,0,sizeof q);
		left=right=q[1]=1;
		for(j=2;j<=m;j++)
		{
			while(left<=right&&j-q[left]<=k)
				left++;
			while(left<=right&&a[q[right]][i]>a[j][i])
				right--;
			q[++right]=j;
			if(j>=k)min_f[j-k+1][i]=a[q[right]][i];
		}
	}
	for(i=1;i<=m-k+1;i++)
	{
		memset(q,0,sizeof q);
		left=right=q[1]=1;
		for(j=2;j<=m;j++)
		{
			while(left<=right&&j-q[left]<=k)
				left++;
			while(left<=right&&min_f[q[right]][i]>min_f[j][i])
				right--;
			q[++right]=j;
			if(j>=k)min_a[j-k+1][i]=min_f[q[right]][i];
		}
	}

	int ans=1e16;
	for(i=1;i<=n-k+1;i++)
		for(j=1;j<=m-k+1;j++)
			ans=min(min_a[i][j]-max_a[i][j],ans);
	cout<<ans<<'\n';
	
	return 0;
}