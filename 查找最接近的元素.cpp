#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
using namespace std;
int a[100009];
int main()
{
	int n,m,i,j,k,t,left,right,mid;
	
	cin>>n;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	cin>>m;
	while(m--)
	{
		cin>>t;
		left=1;
		right=n;
		while(left+1<right)
		{
			mid=(left+right)/2;
			if(t<a[mid])right=mid;
			else left=mid;
			if(abs(a[left]-t)<=abs(a[right]-t))printf("%d\n",a[left]);
			else printf("%d\n",a[right]);
		}
	}
	
	return 0;
}
