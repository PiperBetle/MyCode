#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
int a[300007],d[1000007],bl[300007],sum[607];
bool tag[607];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,flag;
	int l,r,type;
	
	cin>>n>>m;
	for(i=1;i<=1000000;i++)for(j=i;j<=1000000;j+=i)d[j]++;
	int size=sqrt(n),num=0;
	for(i=1;i<=n;i++){cin>>a[i];if(i%size==1)num++;bl[i]=num;sum[num]+=a[i];}
	while(m--)
	{
		cin>>type>>l>>r;
		if(type==1)
		{
			if(bl[l]==bl[r]){for(i=l;i<=r;i++)sum[bl[i]]-=a[i]-d[a[i]],a[i]=d[a[i]];continue;}
			for(i=l;i<=bl[l]*size;i++)sum[bl[i]]-=a[i]-d[a[i]],a[i]=d[a[i]];
			for(i=(bl[r]-1)*size+1;i<=r;i++)sum[bl[i]]-=a[i]-d[a[i]],a[i]=d[a[i]];
			for(i=bl[l]+1;i<bl[r];i++)
			{
				if(tag[i])continue;
				for(flag=1,j=(i-1)*size+1;j<=i*size;j++)
				{
					sum[i]-=a[j]-d[a[j]],a[j]=d[a[j]];
					if(a[j]>2)flag=0;
				}
				if(flag)tag[i]=1;
			}
		}
		else
		{
			int ans=0;
			if(bl[l]==bl[r]){for(i=l;i<=r;i++)ans+=a[i];cout<<ans<<'\n';continue;}
			for(i=l;i<=bl[l]*size;i++)ans+=a[i];
			for(i=(bl[r]-1)*size+1;i<=r;i++)ans+=a[i];
			for(i=bl[l]+1;i<bl[r];i++)ans+=sum[i];
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}