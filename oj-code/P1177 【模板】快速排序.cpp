#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001];
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
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	qs(1,n);
	for(i=1;i<=n;i++)printf("%d ",a[i]);
	
	return 0;
}
