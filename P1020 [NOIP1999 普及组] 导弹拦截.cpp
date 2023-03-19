#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n=1,a[100007];
int d1[100007],d2[100007],l1=1,l2=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	
	while(cin>>a[n])
		n++;
	n--;
	d1[1]=d2[1]=a[1];
	for(i=2;i<=n;i++)
	{
		if(d1[l1]>=a[i])
		{
			l1++;
			d1[l1]=a[i];
		}
		else
		{
			int *p=upper_bound(d1+1,d1+1+l1,a[i],cmp);
			*p=a[i];
		}
		if(d2[l2]<a[i])
		{
			l2++;
			d2[l2]=a[i];
		}
		else
		{
			int *p=lower_bound(d2+1,d2+1+l2,a[i]);
			*p=a[i];
		}
	}
	cout<<l1<<"\n"<<l2;
	
	return 0;
}
