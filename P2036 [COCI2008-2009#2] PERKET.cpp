#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<map>
#include<list>
using namespace std;
struct shit
{
	int suan;
	int ku;
};
int ans=2000000000,n;
shit a[11];
void dfs(int now,int flag,int suan,int ku)
{
	if(now==n+1)
	{
		if(flag==1)ans=min(ans,abs(suan-ku));
		return;
	}
	dfs(now+1,1,suan*a[now].suan,ku+a[now].ku);
	dfs(now+1,flag,suan,ku);
}
int main()
{
	int i,j,k;
	
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i].suan>>a[i].ku;
	dfs(1,0,1,0);
	cout<<ans;
	
	return 0;
}
