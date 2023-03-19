#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[100007];
int main()
{
	int i,j,k;
	int n,m;
	int end,sum=0;
	
	while(cin>>n>>k)
	{
		sum=0;
		if((n==0)&&(k==0))return 0;
		for(i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			if(sum>=k)break;
			sum+=a[i];
		}
		cout<<i-1<<endl;
	}
	
	
	return 0;
}
