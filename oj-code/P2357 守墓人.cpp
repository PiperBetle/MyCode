#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
using std::cin;using std::cout;
int a[200007],sum[507],tag[507],belong[200007];
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int i,j,k;
	int n,m,ans;
	int l,r,type;
	
	cin>>n>>m;
	int size=ceil(sqrt(n)),num=0;
	for(i=1;i<=n;i++){cin>>a[i];if(i%size==1)num++;sum[num]+=a[i];belong[i]=num;}
	while(m--)
	{
		cin>>type;
		switch(type)
		{
		case 1:
			cin>>l>>r>>k;
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)a[i]+=k,sum[belong[i]]+=k;break;}
			for(i=l;i<=belong[l]*size;i++)a[i]+=k,sum[belong[i]]+=k;
			for(i=(belong[r]-1)*size+1;i<=r;i++)a[i]+=k,sum[belong[i]]+=k;
			for(i=belong[l]+1;i<belong[r];i++)tag[i]+=k;
			break;
		case 2:cin>>k;a[1]+=k;sum[1]+=k;break;
		case 3:cin>>k;a[1]-=k;sum[1]-=k;break;
		case 4:
			ans=0;cin>>l>>r;
			if(belong[l]==belong[r]){for(i=l;i<=r;i++)ans+=a[i]+tag[belong[i]];cout<<ans<<'\n';break;}
			for(i=l;i<=belong[l]*size;i++)ans+=a[i]+tag[belong[i]];
			for(i=(belong[r]-1)*size+1;i<=r;i++)ans+=a[i]+tag[belong[i]];
			for(i=belong[l]+1;i<belong[r];i++)ans+=sum[i]+size*tag[i];
			cout<<ans<<'\n';
			break;
		case 5:cout<<a[1]<<'\n';break;
		}
	}
	
	return 0;
}