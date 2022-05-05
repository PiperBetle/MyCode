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
	int i,j,k,t,n,ans=0,zero=0,one=1;
	
	cin>>n;
//	for(i=1;i<=n;i++)
//	{
//		cin>>t;
//		if(t==1)
//		{
//			ans+=one;
//			one=2;
//			if(zero!=0)
//			{
//				ans=ans-pow(2,zero-1);
//				if(ans<0)ans=0;
//			}
//			zero=0;
//		}
//		else
//		{
//			zero++;
//			one=1;
//		}
//	}
//	if(zero!=0)
//	{
//		ans=ans-pow(2,zero-1);
//		if(ans<0)ans=0;
//	}
//	cout<<ans;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1)
		{
			ans+=one;
			one=2;
		}
		else
		{
			one=1;
		}
		cout<<"\""<<ans<<"\"";
	}
	cout<<ans;
	
	return 0;
}
