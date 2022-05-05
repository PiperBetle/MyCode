#include<iostream>
using namespace std;
int main()
{
	
	int i,j,k;
	int n,m,ans=0;
	int a;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a==m)ans++;
	}
	cout<<ans;
	
	return 0;
}
