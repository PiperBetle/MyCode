#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1001];
int ans[1000007]={0,1,0,0},l=1;
int main()
{
	int n,len,i,j,k;
	
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
	len++;
	for(i=2;i<=len;i++)cout<<a[i]<<" ";
	puts("");
	for(k=2;k<=len;k++)
	{
		for(i=1;i<=l;i++)
		{
			ans[i]*=a[k];
		}
		for(i=1;i<=l;i++)
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		for(;;)
		{
			if(ans[l+1]>0)
			{
				l++;
				ans[l+1]=ans[l]/10;
				ans[l]%=10;
			}
			else
			{
				break;
			}
		}
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
