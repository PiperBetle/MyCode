#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int n,a[1001],i;
	
	// 1->1 2->2 3->2 4->4 5->4 6->6
	cin>>n;
	a[1]=1;
	for(i=2;i<=n;i++)
		if(i%2)a[i]=a[i-1];
		else a[i]=a[i/2]+a[i-1];
	cout<<a[n];
	
	return 0;
}
