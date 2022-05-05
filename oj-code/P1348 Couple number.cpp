#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	long long a,b,ans=0,i;
	
	cin>>a>>b;
	for(i=a;i<=b;i++)
	{
		if(i<0)a=-i;
		else a=i;
		if((a%2==1)||(a%4==0))ans++;
	}
	cout<<ans;

	return 0;
}

