#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cmath>
using std::cin;using std::cout;
int a[1000007],tag[1007],belong[1000007],sum[1007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,t;
	int l,r,type;
	
	cin>>n>>m;
	int size=sqrt(n),num=0;
	#define left(x) ((belong[x]-1)*size+1)
	#define right(x) (belong[x]*size)
	for(i=1;i<=n;i++){if(i%size==1)num++;belong[i]=num;}
	while(m--)
	{
		cin>>type>>l>>r;
		if(!type)
		{
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)a[i]=!a[i],sum[belong[i]]+=a[i]?1:-1;continue;}
			for(i=l;i<=right(l);i++)a[i]=!a[i],sum[belong[i]]+=a[i]?1:-1;
			for(i=left(r);i<=r;i++)a[i]=!a[i],sum[belong[i]]+=a[i]?1:-1;
			for(i=belong[l]+1;i<belong[r];i++)tag[i]=!tag[i];
		}
		else
		{
			int ans=0;
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)if(a[i]!=tag[belong[i]])ans++;cout<<ans<<'\n';continue;}
			for(i=l;i<=right(l);i++)if(a[i]!=tag[belong[i]])ans++;
			for(i=left(r);i<=r;i++)if(a[i]!=tag[belong[i]])ans++;
			for(i=belong[l]+1;i<belong[r];i++)ans+=tag[i]?size-sum[i]:sum[i];
			cout<<ans<<'\n';
		}
	}
	
	return 0;
}