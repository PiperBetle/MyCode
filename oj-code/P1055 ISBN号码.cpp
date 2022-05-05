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
	char a[14];
	int flag=0,i,ans=0;
	
	for(i=1;i<=13;i++)cin>>a[i];
	for(i=1;i<=11;i++)
	{
		if((i!=2)&&(i!=6))
		{
			flag++;
			ans=ans+flag*(a[i]-'0');
			cout<<flag<<" "<<i<<' '<<a[i]<<" "<<ans<<endl;
		}
	}
	if((ans%11)==10)
	{
		if(a[13]=='X')cout<<"Right";
		else
		{
			for(i=1;i<=12;i++)cout<<a[i];
			cout<<"X";
		}
	}
	else
	{
		if(a[13]==(ans%11+'0'))cout<<"Right";
		else
		{
			for(i=1;i<=12;i++)cout<<a[i];
			cout<<(char)(ans%11+'0');
		}
	}
	
    return 0;
}
