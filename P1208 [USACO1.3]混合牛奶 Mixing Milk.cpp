#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct cow
{
	int cost;
	int number;
};
bool cmp(cow x,cow y)
{
    if(x.cost!=y.cost)return x.cost<y.cost;
    return x.number>y.number;
}
cow a[5007];
int main()
{
	int i,j,k;
	int n,m,ans=0;
	
	cin>>m>>n;
	for(i=1;i<=n;i++)cin>>a[i].cost>>a[i].number;
	sort(a+1,a+1+n,cmp);
	i=1;
	for(;;)
	{
		if(m==0)break;
		if(a[i].number>0)
		{
			a[i].number--;
			ans+=a[i].cost;
			m--;
		}
		else i++;
	}
	cout<<ans;
	
	return 0;
}
