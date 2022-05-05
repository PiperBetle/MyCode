#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{

//	int n,i,t;
//	long long ans=1,two,five,zero;
//
//	cin>>n;
//	for(i=2;i<=n;i++)
//	{
////		cout<<i<<endl;
//		t=i;
//		while((t%5)==0)
//		{
////			cout<<5;
//			five++;
//			t/=5;
//		}
//		while((t%2)==0)
//		{
////			cout<<2;
//			two++;
//			t/=2;
//		}
//		if(five>0)
//		{
//			two-=five;
//			five=0;
//		}
//		if(two>=1)
//		while(two--)
//		{
//			ans*=2;
//			ans%=10;
//		}
//		ans*=t;
//		ans%=10;
////		cout<<endl;
//	}
//	cout<<ans;
	int a,i,ans;

	cin>>a;
	for(i=2;i<=a;i++)
	{
		ans*=i;
		while(ans%10==0)
		{
			ans/=10;
		}
		ans%=100000;
	}
	cout<<ans%10;

	return 0;
}
