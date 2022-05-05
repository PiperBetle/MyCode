#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int i,j,t;
	int n,m;
	int a[101];
	
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	n=unique(a,a+n)-a;
	cout<<n<<endl;
	cout<<a[0];
	for(i=1;i<n;i++)cout<<" "<<a[i];
	
	return 0;
} 
