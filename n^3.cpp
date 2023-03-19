#include<iostream>
using namespace std;
int main()
{
	int i,j,n,m,k,ans=-1;

//	while(cin>>n)
//	{
//		m=n*n*n;
//		for(I=1;;i+=2)
//		{
//			s=0;
//			for(j=i;;j++)
//			{
//				s+=j;
//				if(s>=m)break;
//			}
//		}
//		if(s==m)break;
//	}
//	cout<<i;
//	for(i=i+2;i<=j;i+=2;)
	while(cin>>n)
	{
		i=n*n-n+1;
		j=n*n+n-1;
		cout<<i;
		for(i=i+2;i<=j;i+=2)
			cout<<" "<<i;
		cout<<endl;
	}
	
	return 0;
} 
