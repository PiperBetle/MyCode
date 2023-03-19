#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int a[10001];
int main()
{
	int i,j,k,t,n,m,ans,len=1,jw;
	
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<=10000;i++)a[i]=0;
		ans=0;
		a[1]=1;
		len=1;
		jw=0;
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=len;j++)
			{
				a[j]*=i;
				a[j]+=jw;
				jw=a[j]/10;
				a[j]%=10;
			}
			for(;;)
			{
				if(jw==0)break;
				len++;
				a[len]=jw%10;
				jw/=10;
			}
		}
		for(i=len;i>=1;i--)
			if(a[i]==m)ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
