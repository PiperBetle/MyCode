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
	long long ans=0;

	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+1+n);
//	for(i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	a[0]=a[1];
	while(m--)
	{
		scanf("%d",&t);
		left=1;
		right=n;
		while(left<right-1)
		{
			mid=left+(right-left)/2;
			if(a[mid]<t)left=mid;
			else right=mid;
		}
//		cout<<a[left]<<" "<<a[right]<<endl;
		if(abs(a[left]-t)<=abs(a[right]-t))ans+=abs(a[left]-t);
		else ans+=abs(a[right]-t);
	}
	printf("%d",ans);

	return 0;
}

