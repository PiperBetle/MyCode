#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<ctime>
#include<cmath>
using namespace std;
int main()
{
	int n,flag=0,ans=0;
	
	cin>>n;
	if(n<0)cout<<'-';
	if(n==0)cout<<0;
	n=abs(n);
    while(n)
	{
		ans=ans*10+n%10;
		n=n/10;
	}
    cout<<ans;
	
	return 0;
}
