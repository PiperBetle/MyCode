#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long a[1001];
int ans[1000007]={0,1,0,0},l=1;
int main()
{
//	freopen("maxmul.in","r",stdin);
//	freopen("maxmul.out","w",stdout);
	long long n,len,i,j,k;
	
	cin>>n;
	for(i=2;;i++)
	{
		if(n>=i)
		{
			len++;
			a[i]=i;
			n-=i;
		}
		else
		{
			a[i-n]++;
			while(n--)
			{
				a[i-n]++;
			}
			break;
		}
	}
	for(i=2;i<=len;i++)cout<<a[i]<<" ";
	puts("");
	for(k=2;k<=len;k++)
	{
		for(i=1;i<=l;i++)
		{
			ans[i]*=a[k];
		}
		for(i=1;i<=l+3;i++)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		if(ans[l+1]>0)l++;
		if(ans[l+1]>0)l++;
		if(ans[l+1]>0)l++;
		if(ans[l+1]>0)l++;
	}
	for(i=l;i>=1;i--)
		if(ans[i]!=0)
		{
			k=i;
			for(;k>=1;k--)cout<<ans[k];
			return 0;
		}
	
	return 0;
}
