#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500007];
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(false);
	int i,j,k;
	int x,y,sum=0,p=0;
	char c;
	
	cin>>k>>k;
	while(k--)
	{
		cin>>c;
		if(c=='A')
		{
			cin>>x;
			for(i=p+1;i<=x;i++)sum+=a[i];
			p=x;
			cout<<sum<<endl;	
		}
		if(c=='B')
		{
			cin>>x>>y;
			if(x<=p)sum+=y;
			else a[x]+=y;
		}
		if(c=='C')
		{
			cin>>x>>y;
			if(x<=p)sum-=y;
			else a[x]-=y;
		}
	}
	
	return 0;
}
