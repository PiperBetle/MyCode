#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
int a[100007],belong[100007],sum[507];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int l,r,type;
	
	cin>>n;
	int size=sqrt(n),num=0;
	for(i=1;i<=n;i++){cin>>a[i];if(i%size==1)num++;belong[i]=num;sum[num]+=a[i];}
	for(cin>>m;m;m--)
	{
		cin>>type>>l>>r;
		if(l>r)std::swap(l,r);
		if(!type)
		{
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)t=a[i],a[i]=sqrt(a[i]),sum[belong[i]]-=t-a[i];continue;}
			for(i=l;i<=belong[l]*size;i++)t=a[i],a[i]=sqrt(a[i]),sum[belong[i]]-=t-a[i];
			for(i=(belong[r]-1)*size+1;i<=r;i++)t=a[i],a[i]=sqrt(a[i]),sum[belong[i]]-=t-a[i];
			for(i=belong[l]+1;i<belong[r];i++)if(sum[i]>size)
				for(j=(i-1)*size+1;j<=i*size;j++)t=a[j],a[j]=sqrt(a[j]),sum[i]-=t-a[j];
		}
		else
		{
			int ans=0;
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)ans+=a[i];cout<<ans<<'\n';continue;}
			for(i=l;i<=belong[l]*size;i++)ans+=a[i];
			for(i=(belong[r]-1)*size+1;i<=r;i++)ans+=a[i];
			for(i=belong[l]+1;i<belong[r];i++)ans+=sum[i];
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}