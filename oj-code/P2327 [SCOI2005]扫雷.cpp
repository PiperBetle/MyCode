#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[10007],n,b[10007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int ans=0,flag;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	
	memset(b,0,sizeof b);
	b[1]=0;
	for(i=2;i<=n;i++)
		b[i]=a[i-1]-b[i-1]-b[i-2];
	flag=1;
	for(i=1;i<=n;i++)
		if(((b[i]!=0)&&(b[i]!=1))||(a[i]!=b[i-1]+b[i]+b[i+1]))
			flag=0;
	ans+=flag;
	
	memset(b,0,sizeof b);
	b[1]=1;
	for(i=2;i<=n;i++)
		b[i]=a[i-1]-b[i-1]-b[i-2];
	flag=1;
	for(i=1;i<=n;i++)
		if(((b[i]!=0)&&(b[i]!=1))||(a[i]!=b[i-1]+b[i]+b[i+1]))
			flag=0;
	ans+=flag;
	
	cout<<ans;
	
	return 0;
}
