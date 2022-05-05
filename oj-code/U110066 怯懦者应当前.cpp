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
int main()
{
	int a[1001],n,i,j,k,minn;
	
	for(;;)
	{
		cin>>n;
		if(n==0)break;
		minn=1;
		cin>>a[1];
		for(i=2;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]<a[minn])minn=i;
		}
		swap(a[1],a[minn]);
		cout<<a[1];
		for(i=2;i<=n;i++)cout<<" "<<a[i];
		cout<<endl;
	}
	
	return 0;
}
