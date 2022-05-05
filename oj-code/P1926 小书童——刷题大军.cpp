#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
int s[1007];//每题的时间
int c[1007],w[1007];//作业的损耗cost 价值worth
int f[1007];//花费j获得的最大分数 
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j;
	int n,m,k,r;//一题时间 作业数量 及格分数 剩余时间
	int ans=0;  
	
	cin>>n>>m>>k>>r;
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<=m;i++)
		cin>>c[i];
	for(i=1;i<=m;i++)
		cin>>w[i];
	
	for(i=1;i<=m;i++)
		for(j=r;j>=c[i];j--)
			f[j]=max(f[j],f[j-c[i]]+w[i]);
	for(i=0;;i++)
		if(f[i]>=k)
			break;
	r-=i;
	
	sort(s+1,s+1+n);
	for(i=1;i<=n;i++)
	{
		if(r<s[i])
			break;
		r-=s[i];
		ans++;
	}
	cout<<ans;
    
    return 0;
}
