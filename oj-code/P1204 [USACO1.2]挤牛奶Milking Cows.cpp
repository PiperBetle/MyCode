#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
using namespace std;
struct cows
{
	int begin,end;
};
cows a[10007];
int cmp(cows a,cows b)
{
	return a.begin<b.begin;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int begin,end,ans1=0,ans2=0;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].begin>>a[i].end;
	sort(a+1,a+1+n,cmp);
	begin=a[1].begin;
	end=a[1].end;
	for(i=2;i<=n;i++)
	{
		if(a[i].begin<=end)end=max(a[i].end,end);
		else
		{
			ans1=max(ans1,end-begin);
			ans2=max(ans2,a[i].begin-end);
			begin=a[i].begin;
			end=a[i].end;
		}
	}
	ans1=max(ans1,end-begin);
	cout<<ans1<<" "<<ans2;
	
	return 0;
}
