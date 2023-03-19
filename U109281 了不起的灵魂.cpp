#include<iostream>
#include<cstdio>
#include<algorithm>
int a[2007];
using namespace std;
int main()
{
	int n,ans=1;
	
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)scanf("%d",a+i);
	for(register int i=1;i<n;++i)if(a[i]!=a[i+1]){ans=0;break;}
	if(ans==1){puts("0");return 0;}
	sort(a+1,a+1+n);
	for(register int i=1;i<=n-2;++i)
	{
		for(register int j=i+1;j<=n-1;++j)
		{
			for(register int k=j+1;k<=n;++k)
			{
				if(a[k]>a[i]+a[j])
				{
					ans+=n-k+1;
					break;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
}
