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
using namespace std;
string a[1000001],b[100001];
int main()
{
	int n,i;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n-1;i++)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+n);
	for(i=1;i<=n-1;i++)
		if(a[i]!=b[i])
		{
			cout<<a[i];
			return 0;
		}
	cout<<a[n];
	
    return 0;
}
