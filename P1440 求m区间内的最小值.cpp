#include<iostream>
#include<cstring>
#include<cstdio>
#include<deque>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
using namespace std;
struct number
{
	int data,ID;
};
number a[2000007];
deque<number> q;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int i,j,k;
	int n,m,p;
	
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].ID=i;
	}
	printf("0");
	for(i=1;i<=n-1;i++)
	{
		while(!q.empty()&&q.back().data>a[i].data)
			q.pop_back();
		q.push_back(a[i]);
		if(q.front().ID==i-k)
			q.pop_front();
		printf("\n%d",q.front().data);
	}
	
    return 0;
}
