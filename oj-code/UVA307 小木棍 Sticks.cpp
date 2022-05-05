#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[107],used[107],n,l;
bool dfs(int now,int last,int sum)
{
	if(now==n&&sum==0)return 1;
	int left=0,right=n-1,mid;
	if(sum==0)sum=l;
	if(sum!=l)left=last+1;
	while(left<right)
	{
		mid=left+right>>1;
		if(a[mid]<=sum)right=mid;
		else left=mid+1;
	}
	for(int i=left;i<n;i++)
	{
		if(used[i]||a[i]>sum)continue;
		if(i>0&&!used[i-1]&&a[i-1]==a[i])continue;
		used[i]=1;
		if(dfs(now+1,i,sum-a[i]))return 1;
		used[i]=0;
		if(sum==l||a[i]==sum)return 0;
	}
	return 0;
}
int main()
{
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
	int i,j,k;
	
	while(cin>>n)
	{
		int total=0;
		for(i=0;i<n;i++)scanf("%d",&a[i]),total+=a[i];
		memset(used,0,sizeof used);
		sort(a,a+n,greater<int>());
		for(l=a[0];l<=total/2;l++)
		{
			if(total%l)continue;
			if(dfs(0,0,l))
			{
				cout<<l<<'\n'
			}
		}
		cout<<total<<'\n';
	}
	
	return 0;
}
