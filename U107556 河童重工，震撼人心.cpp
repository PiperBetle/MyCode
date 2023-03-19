#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
using namespace std;
int maxam=99999999,a[40001],n,m;
void s(int t,int sum)
{
	if(sum>maxam)return;
	if((t-1)>n)return;
	if((t-1)==n)
	{
		if(sum>=m)
			if(sum<maxam)
				maxam=sum;
	}
	s(t+1,sum+a[t]);
	s(t+1,sum);
}
int main()
{
	int i,j,b,c;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	s(0,0);
	cout<<maxam-m;
	
	return 0;
}
