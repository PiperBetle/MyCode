#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int prime(int m)
{
	if(m<2)return 0;
	if(m<4)return 1;
	int i;
	for(i=2;i*i<=m;i++)
		if(m%i==0)return 0;
 	return 1;
}
int main()
{
	int n,i,ans=0;
	
	cin>>n;
	for(i=2;;i++)
	{
		if(prime(i)==1)
		{
			n-=i;
			if(n<0)break;
			cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}
