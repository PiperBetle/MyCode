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
int a[100007]={0};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int n,m,t;
	int left,right;
	
	cin>>n>>m;
	while(m--)
	{
		cin>>left>>right;
		a[left]++;
		a[right+1]--;
	}
	for(i=1;i<=n;i++)
	{
		a[i]+=a[i-1];
		if(a[i]!=1)
		{
			cout<<i<<' '<<a[i];
			return 0;
		}
	}
	cout<<"OK";
	
	return 0;
}
