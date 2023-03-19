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
#define n 4
using namespace std;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int a[11];
	
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	cout<<a[4]-a[1]<<" "<<a[4]-a[2]<<" "<<a[4]-a[3]; 
	
	return 0;
}
