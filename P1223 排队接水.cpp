#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001],b[100001];
void qs(int left,int right)
{
	int i,j,k,mid;
	i=left;
	j=right;
	mid=a[(left+right)/2];
	do
	{
		while(a[i]<mid)i++;
		while(a[j]>mid)j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
	}
	while(i<=j);
	if(left<j)qs(left,j);
	if(i<right)qs(i,right);
}
int main()
{
	int i,j,k,n;
	double sum=0;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		b[i]=i;
	}
	qs(1,n);
	for(i=2;i<=n;i++)
	{
		a[i]+=a[i-1];
		sum+=a[i-1];
	}
	for(i=1;i<=n;i++)printf("%d ",b[i]);
	printf("\n%.2f",sum/(double)n);

	return 0;
}
