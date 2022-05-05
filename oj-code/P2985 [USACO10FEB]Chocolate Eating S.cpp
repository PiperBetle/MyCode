#include<iostream>
#include<cstring>
#include<cstdio>
#define int unsigned long long
using namespace std;
int h[1000007],b[1000007];// h->happy b->¼ÇÂ¼ÈÕÆÚ 
int n,d,sum,ans;
bool check(int x)
{
	memset(b,0,sizeof b);
	int happy=0,now=0;
	for(int i=1;i<=d;i++)
	{
		happy>>=1;
		while(happy<x)
		{
			now++;
			happy+=h[now];
			b[now]=i;
			if(now>n)
				return 0;
//			cout<<now<<" "<<happy<<" "<<x<<endl;
		}
	}
	return 1;
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	
	cin>>n>>d;
	for(i=1;i<=n;i++)
	{
		cin>>h[i];
		sum+=h[i];
	}
//	cout<<"First\n";
	int left=0,right=sum,mid;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(!check(mid))
			right=mid-1;
		else
		{
			left=mid+1;
			ans=mid;
		}
	}
	
	cout<<ans<<'\n';
	check(ans);
	for(i=1;i<=n;i++)
		if(b[i])
			cout<<b[i]<<'\n';
		else
			cout<<d<<'\n';
	
    return 0;
}
