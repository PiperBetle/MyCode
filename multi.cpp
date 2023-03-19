#include<iostream>
using namespace std;
int main()
{
	int i,j,k,a,b,c,ans,flag=0;
	int sum[301];
	
	cin>>a>>b>>c;
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			for(k=1;k<=c;k++)
				sum[i+j+k]++;
	ans=sum[3];
	for(i=4;i<=a+b+c;i++)
	{
		if(sum[i]>ans)ans=sum[i];
	}
	for(i=3;i<=a+b+c;i++)
	{
		if(sum[i]==ans)
		{
			if(!flag)flag=1;
			else cout<<" ";
			cout<<i;
		}
	}
	cout<<endl;
	
	return 0;
} 
